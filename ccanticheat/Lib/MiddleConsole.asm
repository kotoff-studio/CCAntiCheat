.386
.model flat, stdcall
option casemap:none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\kernel32.lib
 
.data
        msg db "ADK-Win-Command", 13, 10
        msg db "Windows Middle Console", 13, 10
        len equ $-msg
 
.data?
        written dd ?
 
.code
start:
        push    -11
        call    GetStdHandle
 
        push    0
        push    OFFSET written
        push    len
        push    OFFSET msg
        push    eax
        call    WriteFile
 
        push    0
        call    ExitProcess

end start
