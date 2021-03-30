set nocompatible              " be iMproved, required
filetype off                  " required

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Plugin 'ascenator/L9', {'name': 'newL9'}
" 이부분에 플러그인 설치할 부분을 넣어주면 된다.
Plugin 'xolox/vim-easytags'
Plugin 'xolox/vim-misc'
Plugin 'majutsushi/tagbar'

" All of your Plugins must be added before the following line
call vundle#end()            " required

" 플러그인 설정 관련 부분은 vundle#end 밑에줄에 넣어주면 된다.
filetype plugin indent on    " required


" vim runtime configuration file
syntax on
"filetype plugin indent on
set tag=./tags;/
" easy-tag " tags를 비동기로 불러와준다. (필수) tag사이즈가 커지게 되면 vim이 블록되는 시간이 길어져서 답답하다 
let g:easytags_async=1
" highlight를 켜면 좋지만 이것도 속도가 느려진다. 
let g:easytags_auto_highlight = 0
" struct의 멤버변수들도 추적이 된다. 
let g:easytags_include_members = 1
" 현재 프로젝트에서 쓰는 tags파일을 우선 로드하고 없을 경우 global tags를 로드한다. 
let g:easytags_dynamic_files = 1

set ai
set cindent
set ts=8 sw=4 sts=4
set smartindent
set nu
set hlsearch
set cursorline
 
function! LoadCscope()
  let db = findfile("cscope.out", ".;")
  if (!empty(db))
    let path = strpart(db, 0, match(db, "/cscope.out$"))
    set nocscopeverbose " suppress 'duplicate connection' error
    exe "cs add " . db . " " . path
    set cscopeverbose
  endif
endfunction
call LoadCscope()

nmap <F8> :TagbarToggle<CR>

"set tags=/home/song/Dev/AOSP/Q/tags,/home/song/Dev/sqlite/sqlite
"set tags=/home/song/Dev/sqlite/SQLite-3_22_0-0c55d179/tags
"set tags=/home/song/Dev/sqlite/sqlite/tags


