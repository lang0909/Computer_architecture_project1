# Implementing a MIPS Assembler

## 개요
이 프로젝트는 MIPS ISA assembler를 구현하는 것이다. assembler는 assembly code를 binary 파일로 변환하는 도구이다.
이 프로젝트의 목표는 MIPS ISA instruction set을 이해하고 assembler의 원리를 숙지하기 위한 것이다.


## 사용된 환경 & version
- Ubuntu 18.04.1 LTS (64bit)
- gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0


## 사용 시 주의사항

**object파일 생성 및 assembler 테스트**

```bash
make
make test
```

**생성 된 object파일 삭제**

```bash
make clean
```


## 기능 설명
### Instruction Set

- 상세한 instruction 정보는 /handout/MIPS_Green_Sheet.pdf 를 참고한다
    - **Only instructions for unsigned operations need to be implemented.** (addu, addiu, subu, sltiu, sltu, sll, srl)
    - **However, the immediate fields for certain instructions are sign extended to allow negative numbers** (addui, beq, bne, lw, sw, sltui)
    - **Only loads and stores with 4B word need to be implemented.**
    - **The assembler must support decimal and hexadecimal numbers (0x) for the immediate field, and** *.data* **section.**
    - **The register name is always** *“$n”* **n is from 0 to 31.**
    - la **(load address) is a pseudo instruction; it should be converted to one or two assembly instructions.**
    
    
    la $2, VAR1: VAR1 is a label in the data section
    - It should be converted to lui and ori instructions.
    - lui $register, upper 16bit address
    - ori $register, lower 16bit address
    - If the lower 16bit address is 0x0000, the ori instruction is useless.
        - Case1) load address is 0x1000 0000
            - lui $2, 0x1000
        - Case2) load address is 0x1000 0004
            - lui $2, 0x1000
            - ori $2, $2, 0x0004
            
###Directives
- .text
    - indicates that following items are stored in the user text segment, typically instructions
    - It always starts from 0x400000
- .data
    - indicates that following data items are stored in the data segment
    - It always starts from 0x10000000
- .word
    - store n 32-bit quantities in successive memory words
    
- You can assume that the .data and .text directives appear only once, and the .data must appear
  before .text directive. Assume that each word in the data section is initialized (Each word has an
  initial value). In the following figure, we illustrate the memory map used in our projects.
  


### 입력예시



### 출력예시

The output of the assembler is an object file. We use a simplified custom format.
- The first two words (32bits) are the size of text section, and data section.
- The next bytes are the instructions in binary. The length must be equal to the specified text section
length.
- After the text section, the rest of bytes are the initial values of the data section.

The following must be the final binary format:

<text section size>
<data section size>
<instruction 1>
…
<instruction n>