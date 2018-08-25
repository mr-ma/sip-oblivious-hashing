#pragma once

#include <vector>
#include <unordered_map>

namespace llvm {
class MemorySSA;
class Instruction;
class BasicBlock;
class Function;
}

namespace oh {

class MemoryDefinitionData
{
public:

    struct DefInfo {
        llvm::BasicBlock* defBlock;
        llvm::Instruction* defInstr;
    };
    using DefInfos = std::vector<DefInfo>;

public:
    MemoryDefinitionData(llvm::Function& F, llvm::MemorySSA& ssa);


    void collectDefiningData();
    const DefInfos& getDefinitionData(llvm::Instruction* I);
    const DefInfos& getDefinitionData(llvm::Instruction* I) const;

private:
    llvm::Function& m_F;
    llvm::MemorySSA& m_memorySSA;
    std::unordered_map<llvm::Instruction*, DefInfos> m_definingBlocks;
};

}

