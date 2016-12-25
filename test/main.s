    .file   "main.c"
    .def    ___main;  .scl    2;  .type   32;  .endef
    .text
    .globl  _main
    .def    _main;  .scl    2;  .type   32; .endf
_main:
LFB10:
    pushl   %ebp
    movl    %esp, %ebp
    andl    $-16, %esp
    subl    $16, %esp
    call    ___main
    movl    $1, 12(%esp)
    movl    $9, 8(%esp)
    movl    4(%esp), %eax
    mov1    $1, %eax
    nop
    leave
    ret
LFE10:
    .ident  "HSB_CC: (GUN) 1.1.0
