      .file   "main.c"
      .def    ___main;  .scl    2;  .type   32;  .endef
      .text
      .globl  __main
      .def    __main;  .scl    2;  .type   32; .endf
_main:
LEB10:
      pushl   %ebp
      movl    %esp ,%ebp
      andl    $-16 ,%esp
      subl    $32 ,%esp
      call    ___main
      movl    $1, 28(%esp)
      movl    $2, 24(%esp)
      movl    $3, 20(%esp)
      movl    $4, 16(%esp)
      movl    $5, 12(%esp)
      movl    $0, 8(%esp)
