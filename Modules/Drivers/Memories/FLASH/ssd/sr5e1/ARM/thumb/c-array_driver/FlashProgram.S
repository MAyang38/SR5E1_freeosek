.text  // This is code
       .thumb // We will be using thumb code
	   .thumb_func

       .globl FlashProgram_C // FlashProgram_C is externally visible

FlashProgram_C:
       .word 0xB08BB480, 0x60F8AF00, 0x603B607A, 0x72FB460B
       .word 0x61BB2300, 0xF89368FB, 0x2B003040, 0x7AFBD106
       .word 0xD0032B00, 0x7380F44F, 0xE0A861BB, 0xF003687B
       .word 0x2B000307, 0x6B3AD106, 0x4313683B, 0x0303F003
       .word 0xD0022B00, 0x61BB2301, 0x68FBE099, 0x3040F893
       .word 0xD0032B00, 0x681B68FB, 0xE003623B, 0x681B68FB
       .word 0x623B3304, 0x681B6A3B, 0x69FB61FB, 0x0310F003
       .word 0xD0042B00, 0xF00369FB, 0x2B000309, 0x69FBD109
       .word 0x0304F003, 0xD0072B00, 0xF00369FB, 0x2B000302
       .word 0x2304D102, 0xE07261BB, 0x2B00683B, 0x6A3BD06E
       .word 0x4B3F681A, 0x6A3A4013, 0x0310F043, 0x6A3B6013
       .word 0xF003681B, 0x2B000310, 0x2302D102, 0xE05E61BB
       .word 0x2B007AFB, 0x6A3BD017, 0x4B36681A, 0x6A3A4013
       .word 0x0380F043, 0x6A3B6013, 0xF003681B, 0x2B000380
       .word 0x6A3BD109, 0x6A3A6819, 0x400B4B2D, 0xF44F6013
       .word 0x61BB7300, 0x68FBE043, 0x683A6C5B, 0xD903429A
       .word 0x6C5B68FB, 0xE001617B, 0x617B683B, 0x089B697B
       .word 0x2300613B, 0xE019627B, 0x687B6B3A, 0x601A6812
       .word 0x3304687B, 0x6B3B607B, 0x633B3304, 0x3B04683B
       .word 0x68FB603B, 0x687B6C5A, 0xF1F2FBB3, 0xF201FB02
       .word 0x2B001A9B, 0x6A7BD007, 0x627B3301, 0x6A7A693B
       .word 0xD3E1429A, 0xBF00E000, 0x687A6B7B, 0x6B7B601A
       .word 0x605A683A, 0x6B3A6B7B, 0x6A3B609A, 0x4B0E681A
       .word 0x6A3A4013, 0x0301F043, 0xE0006013, 0x68FBBF00
       .word 0x3048F893, 0xD0042B00, 0x461B69BB, 0xDF0CBF00
       .word 0x69BBBF00, 0x372C4618, 0xF85D46BD, 0x47707B04
       .word 0xFFFF1FEF, 0xFFFF1F7F, 0xFFFF1FFE
       ;  // FlashProgram_C is a function