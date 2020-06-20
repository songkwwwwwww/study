" vim runtime configuration file
syntax on
filetype plugin indent on

set ai
set cindent
set ts=8 sw=4 sts=4
set smartindent
set nu
set hlsearch
set cursorline

" man page setting
func! Man()
    let sm = expand("<cword>")
    exe "!man -S 2:3:4:5:6:7:8:9:tcl:n:l:p:o ".sm
endfunc
nmap ,ma :call Man()<cr><cr>


"set tags=/home/song/Dev/AOSP/P/tags
set tags=/home/song/Dev/AOSP/Q/tags,/home/song/Dev/sqlite/sqlite
"set tags=/home/song/Dev/sqlite/SQLite-3_22_0-0c55d179/tags
"set tags=/home/song/Dev/sqlite/sqlite/tags
