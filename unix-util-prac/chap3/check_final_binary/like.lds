Archive member included to satisfy reference by file (symbol)

/usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
                              /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o (__libc_csu_init)

Discarded input sections

 .note.GNU-stack
                0x0000000000000000        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 .note.GNU-stack
                0x0000000000000000        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
 .note.GNU-stack
                0x0000000000000000        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
 .note.GNU-stack
                0x0000000000000000        0x0 like.o
 .note.GNU-stack
                0x0000000000000000        0x0 /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
 .note.GNU-stack
                0x0000000000000000        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o
 .note.GNU-stack
                0x0000000000000000        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o

Memory Configuration

Name             Origin             Length             Attributes
*default*        0x0000000000000000 0xffffffffffffffff

Linker script and memory map

LOAD /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
LOAD like.o
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/libgcc.a
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/libgcc_s.so
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/libc.so
START GROUP
LOAD /lib/x86_64-linux-gnu/libc.so.6
LOAD /usr/lib/x86_64-linux-gnu/libc_nonshared.a
LOAD /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
END GROUP
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/libgcc.a
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/libgcc_s.so
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o
LOAD /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o
                [!provide]                        PROVIDE (__executable_start, 0x400000)
                0x0000000000400238                . = (0x400000 + SIZEOF_HEADERS)

.interp         0x0000000000400238       0x1c
 *(.interp)
 .interp        0x0000000000400238       0x1c /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.note.ABI-tag   0x0000000000400254       0x20
 .note.ABI-tag  0x0000000000400254       0x20 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.note.gnu.build-id
                0x0000000000400274       0x24
 *(.note.gnu.build-id)
 .note.gnu.build-id
                0x0000000000400274       0x24 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.hash
 *(.hash)

.gnu.hash       0x0000000000400298       0x1c
 *(.gnu.hash)
 .gnu.hash      0x0000000000400298       0x1c /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.dynsym         0x00000000004002b8       0x60
 *(.dynsym)
 .dynsym        0x00000000004002b8       0x60 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.dynstr         0x0000000000400318       0x3d
 *(.dynstr)
 .dynstr        0x0000000000400318       0x3d /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.gnu.version    0x0000000000400356        0x8
 *(.gnu.version)
 .gnu.version   0x0000000000400356        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.gnu.version_d  0x0000000000400360        0x0
 *(.gnu.version_d)
 .gnu.version_d
                0x0000000000400360        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.gnu.version_r  0x0000000000400360       0x20
 *(.gnu.version_r)
 .gnu.version_r
                0x0000000000400360       0x20 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.rela.dyn       0x0000000000400380       0x18
 *(.rela.init)
 *(.rela.text .rela.text.* .rela.gnu.linkonce.t.*)
 .rela.text     0x0000000000400380        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 *(.rela.fini)
 *(.rela.rodata .rela.rodata.* .rela.gnu.linkonce.r.*)
 *(.rela.data .rela.data.* .rela.gnu.linkonce.d.*)
 *(.rela.tdata .rela.tdata.* .rela.gnu.linkonce.td.*)
 *(.rela.tbss .rela.tbss.* .rela.gnu.linkonce.tb.*)
 *(.rela.ctors)
 *(.rela.dtors)
 *(.rela.got)
 .rela.got      0x0000000000400380       0x18 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 *(.rela.bss .rela.bss.* .rela.gnu.linkonce.b.*)
 .rela.bss      0x0000000000400398        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 *(.rela.ldata .rela.ldata.* .rela.gnu.linkonce.l.*)
 *(.rela.lbss .rela.lbss.* .rela.gnu.linkonce.lb.*)
 *(.rela.lrodata .rela.lrodata.* .rela.gnu.linkonce.lr.*)
 *(.rela.ifunc)

.rela.plt       0x0000000000400398       0x30
 *(.rela.plt)
 .rela.plt      0x0000000000400398       0x30 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                [!provide]                        PROVIDE (__rela_iplt_start, .)
 *(.rela.iplt)
 .rela.iplt     0x00000000004003c8        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                [!provide]                        PROVIDE (__rela_iplt_end, .)

.init           0x00000000004003c8       0x1a
 *(SORT(.init))
 .init          0x00000000004003c8       0x15 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
                0x00000000004003c8                _init
 .init          0x00000000004003dd        0x5 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o

.plt            0x00000000004003f0       0x30
 *(.plt)
 .plt           0x00000000004003f0       0x30 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x0000000000400400                puts@@GLIBC_2.2.5
                0x0000000000400410                __libc_start_main@@GLIBC_2.2.5
 *(.iplt)
 .iplt          0x0000000000400420        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.plt.got        0x0000000000400420        0x8
 *(.plt.got)
 .plt.got       0x0000000000400420        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.plt.bnd
 *(.plt.bnd)

.text           0x0000000000400430      0x182
 *(.text.unlikely .text.*_unlikely .text.unlikely.*)
 .text.unlikely
                0x0000000000400430        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
 .text.unlikely
                0x0000000000400430        0x0 /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
 *(.text.exit .text.exit.*)
 *(.text.startup .text.startup.*)
 *(.text.hot .text.hot.*)
 *(.text .stub .text.* .gnu.linkonce.t.*)
 .text          0x0000000000400430       0x2a /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x0000000000400430                _start
 .text          0x000000000040045a        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
 *fill*         0x000000000040045a        0x6 
 .text          0x0000000000400460       0xc6 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
 .text          0x0000000000400526       0x15 like.o
                0x0000000000400526                main
 *fill*         0x000000000040053b        0x5 
 .text          0x0000000000400540       0x72 /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
                0x0000000000400540                __libc_csu_init
                0x00000000004005b0                __libc_csu_fini
 .text          0x00000000004005b2        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o
 .text          0x00000000004005b2        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o
 *(.gnu.warning)

.fini           0x00000000004005b4        0x9
 *(SORT(.fini))
 .fini          0x00000000004005b4        0x4 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
                0x00000000004005b4                _fini
 .fini          0x00000000004005b8        0x5 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o
                [!provide]                        PROVIDE (__etext, .)
                [!provide]                        PROVIDE (_etext, .)
                [!provide]                        PROVIDE (etext, .)

.rodata         0x00000000004005c0       0x10
 *(.rodata .rodata.* .gnu.linkonce.r.*)
 .rodata.cst4   0x00000000004005c0        0x4 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x00000000004005c0                _IO_stdin_used
 .rodata        0x00000000004005c4        0xc like.o

.rodata1
 *(.rodata1)

.eh_frame_hdr   0x00000000004005d0       0x34
 *(.eh_frame_hdr)
 .eh_frame_hdr  0x00000000004005d0       0x34 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x00000000004005d0                __GNU_EH_FRAME_HDR
 *(.eh_frame_entry .eh_frame_entry.*)

.eh_frame       0x0000000000400608       0xf4
 *(.eh_frame)
 .eh_frame      0x0000000000400608       0x30 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 .eh_frame      0x0000000000400638       0x40 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 .eh_frame      0x0000000000400678       0x20 like.o
                                         0x38 (size before relaxing)
 .eh_frame      0x0000000000400698       0x60 /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
                                         0x78 (size before relaxing)
 .eh_frame      0x00000000004006f8        0x4 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o
 *(.eh_frame.*)

.gcc_except_table
 *(.gcc_except_table .gcc_except_table.*)

.gnu_extab
 *(.gnu_extab*)

.exception_ranges
 *(.exception_ranges .exception_ranges*)
                0x0000000000600e10                . = DATA_SEGMENT_ALIGN (0x200000, 0x1000)

.eh_frame
 *(.eh_frame)
 *(.eh_frame.*)

.gnu_extab
 *(.gnu_extab)

.gcc_except_table
 *(.gcc_except_table .gcc_except_table.*)

.exception_ranges
 *(.exception_ranges .exception_ranges*)

.tdata
 *(.tdata .tdata.* .gnu.linkonce.td.*)

.tbss
 *(.tbss .tbss.* .gnu.linkonce.tb.*)
 *(.tcommon)

.preinit_array  0x0000000000600e10        0x0
                [!provide]                        PROVIDE (__preinit_array_start, .)
 *(.preinit_array)
                [!provide]                        PROVIDE (__preinit_array_end, .)

.init_array     0x0000000000600e10        0x8
                0x0000000000600e10                PROVIDE (__init_array_start, .)
 *(SORT(.init_array.*) SORT(.ctors.*))
 *(.init_array EXCLUDE_FILE(*crtend?.o *crtend.o *crtbegin?.o *crtbegin.o) .ctors)
 .init_array    0x0000000000600e10        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
                0x0000000000600e18                PROVIDE (__init_array_end, .)

.fini_array     0x0000000000600e18        0x8
                [!provide]                        PROVIDE (__fini_array_start, .)
 *(SORT(.fini_array.*) SORT(.dtors.*))
 *(.fini_array EXCLUDE_FILE(*crtend?.o *crtend.o *crtbegin?.o *crtbegin.o) .dtors)
 .fini_array    0x0000000000600e18        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
                [!provide]                        PROVIDE (__fini_array_end, .)

.ctors
 *crtbegin.o(.ctors)
 *crtbegin?.o(.ctors)
 *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
 *(SORT(.ctors.*))
 *(.ctors)

.dtors
 *crtbegin.o(.dtors)
 *crtbegin?.o(.dtors)
 *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
 *(SORT(.dtors.*))
 *(.dtors)

.jcr            0x0000000000600e20        0x8
 *(.jcr)
 .jcr           0x0000000000600e20        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
 .jcr           0x0000000000600e20        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o

.data.rel.ro
 *(.data.rel.ro.local* .gnu.linkonce.d.rel.ro.local.*)
 *(.data.rel.ro .data.rel.ro.* .gnu.linkonce.d.rel.ro.*)

.dynamic        0x0000000000600e28      0x1d0
 *(.dynamic)
 .dynamic       0x0000000000600e28      0x1d0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x0000000000600e28                _DYNAMIC

.got            0x0000000000600ff8        0x8
 *(.got)
 .got           0x0000000000600ff8        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 *(.igot)
                0x0000000000601fe8                . = DATA_SEGMENT_RELRO_END (., (SIZEOF (.got.plt) >= 0x18)?0x18:0x0)

.got.plt        0x0000000000601000       0x28
 *(.got.plt)
 .got.plt       0x0000000000601000       0x28 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x0000000000601000                _GLOBAL_OFFSET_TABLE_
 *(.igot.plt)
 .igot.plt      0x0000000000601028        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o

.data           0x0000000000601028       0x10
 *(.data .data.* .gnu.linkonce.d.*)
 .data          0x0000000000601028        0x4 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
                0x0000000000601028                data_start
                0x0000000000601028                __data_start
 .data          0x000000000060102c        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
 *fill*         0x000000000060102c        0x4 
 .data          0x0000000000601030        0x8 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
                0x0000000000601030                __dso_handle
 .data          0x0000000000601038        0x0 like.o
 .data          0x0000000000601038        0x0 /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
 .data          0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o
 .data          0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o

.tm_clone_table
                0x0000000000601038        0x0
 .tm_clone_table
                0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
 .tm_clone_table
                0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o

.data1
 *(.data1)
                0x0000000000601038                _edata = .
                [!provide]                        PROVIDE (edata, .)
                0x0000000000601038                . = .
                0x0000000000601038                __bss_start = .

.bss            0x0000000000601038        0x8
 *(.dynbss)
 .dynbss        0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 *(.bss .bss.* .gnu.linkonce.b.*)
 .bss           0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crt1.o
 .bss           0x0000000000601038        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crti.o
 .bss           0x0000000000601038        0x1 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
 .bss           0x0000000000601039        0x0 like.o
 .bss           0x0000000000601039        0x0 /usr/lib/x86_64-linux-gnu/libc_nonshared.a(elf-init.oS)
 .bss           0x0000000000601039        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o
 .bss           0x0000000000601039        0x0 /usr/lib/gcc/x86_64-linux-gnu/5/../../../x86_64-linux-gnu/crtn.o
 *(COMMON)
                0x0000000000601040                . = ALIGN ((. != 0x0)?0x8:0x1)
 *fill*         0x0000000000601039        0x7 

.lbss
 *(.dynlbss)
 *(.lbss .lbss.* .gnu.linkonce.lb.*)
 *(LARGE_COMMON)
                0x0000000000601040                . = ALIGN (0x8)
                0x0000000000601040                . = SEGMENT_START ("ldata-segment", .)

.lrodata
 *(.lrodata .lrodata.* .gnu.linkonce.lr.*)

.ldata          0x0000000000a01040        0x0
 *(.ldata .ldata.* .gnu.linkonce.l.*)
                0x0000000000a01040                . = ALIGN ((. != 0x0)?0x8:0x1)
                0x0000000000a01040                . = ALIGN (0x8)
                0x0000000000a01040                _end = .
                [!provide]                        PROVIDE (end, .)
                0x0000000000a01040                . = DATA_SEGMENT_END (.)

.stab
 *(.stab)

.stabstr
 *(.stabstr)

.stab.excl
 *(.stab.excl)

.stab.exclstr
 *(.stab.exclstr)

.stab.index
 *(.stab.index)

.stab.indexstr
 *(.stab.indexstr)

.comment        0x0000000000000000       0x34
 *(.comment)
 .comment       0x0000000000000000       0x34 /usr/lib/gcc/x86_64-linux-gnu/5/crtbegin.o
                                         0x35 (size before relaxing)
 .comment       0x0000000000000034       0x35 like.o
 .comment       0x0000000000000034       0x35 /usr/lib/gcc/x86_64-linux-gnu/5/crtend.o

.debug
 *(.debug)

.line
 *(.line)

.debug_srcinfo
 *(.debug_srcinfo)

.debug_sfnames
 *(.debug_sfnames)

.debug_aranges
 *(.debug_aranges)

.debug_pubnames
 *(.debug_pubnames)

.debug_info
 *(.debug_info .gnu.linkonce.wi.*)

.debug_abbrev
 *(.debug_abbrev)

.debug_line
 *(.debug_line .debug_line.* .debug_line_end)

.debug_frame
 *(.debug_frame)

.debug_str
 *(.debug_str)

.debug_loc
 *(.debug_loc)

.debug_macinfo
 *(.debug_macinfo)

.debug_weaknames
 *(.debug_weaknames)

.debug_funcnames
 *(.debug_funcnames)

.debug_typenames
 *(.debug_typenames)

.debug_varnames
 *(.debug_varnames)

.debug_pubtypes
 *(.debug_pubtypes)

.debug_ranges
 *(.debug_ranges)

.debug_macro
 *(.debug_macro)

.gnu.attributes
 *(.gnu.attributes)

/DISCARD/
 *(.note.GNU-stack)
 *(.gnu_debuglink)
 *(.gnu.lto_*)
OUTPUT(like elf64-x86-64)
