"Set mapleader"
"let mapleader = ","  
"let g:mapleader = "," 

"显示行号 
set nu 

"打开语法高亮 
syntax enable
syntax on 

set softtabstop=4 
set shiftwidth=4 

"设置tab键长为4
set tabstop=4

"关闭自动备份 
set nobackup 

"set guioptions-=T  "隐藏工具栏
"set guioptions-=m  "隐藏菜单栏

"set a.vim
"nnoremap <silent><F12> :A<CR> 

"自动缩进设置 
set cindent 
set smartindent 
set incsearch 
set autoindent 

"Show matching bracets 
set showmatch 

"Get out of VI's compatible mode 
set nocompatible 

"Have the mouse enabled all the time 
set mouse=a

"Set to auto read when a file is changed from the outside 
set autoread 

"Enable filetype plugin 
filetype plugin on 
filetype indent on 

"设置配色方案为torte 
"color torte 
"color ron   "不好
color desert

"设置打开文件时的编码
set encoding=utf-8

"设置支持的文件编码类项，目前设置为utf-8和gbk两种类型 
set fileencodings=utf-8,gb2312,gbk,gb18030
"set termencoding=utf-8
"set fileformats=unix
"set encoding=prc

"显示中文帮助
if version >=603
	set helplang=cn
	set encoding=utf-8
endif
set helplang=cn
set langmenu=zh_CN.UTF-8

"设置编辑的文件保存时的编码方式
"set fileencoding=utf-8

"设置搜索结果高亮显示 
set hlsearch 

"显示括号匹配情况
set magic

"右下角显示光标状态行
set ruler
set cul
set cuc

"设置Ctrl+c复制
vmap <C-c> "+y

"设置退格键和delete键删除
set backspace=indent,eol,start

"set cscope
set cscopequickfix=s-,c-,d-,i-,t-,e-

"设置记录的历史操作列表 
set history=100 

"设置折叠 
set foldcolumn=2 
set foldmethod=indent 
set foldlevel=3

"括号自动补全 () [] {} 等
:inoremap ( ()<ESC>i
:inoremap ) <c-r>=ClosePair(')')<CR>
:inoremap { {<CR>}<ESC>O
:inoremap } <c-r>=ClosePair('}')<CR>
:inoremap [ []<ESC>i
:inoremap ] <c-r>=ClosePair(']')<CR>
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i

"AutoCommand 
"新建.c,.cpp,.h,.hpp.sh,.java文件，自动插入文件头 
autocmd BufNewFile *.[ch],*.hpp,*.cpp,*.sh,*.java exec ":call SetTitle()" 
"新建文件后，自动定位到文件末尾 
autocmd BufNewFile * normal G 

""/////////////////////////////////////////
"代码补全
set completeopt=preview,menu
filetype plugin indent on
set completeopt=longest,menu
"设置Java代码的自动补全 
set wildmenu
""au FileType java setlocal omnifunc=javacomplete#Complete 
autocmd FileType java set omnifunc=javacomplete#Complete 
autocmd FileType Python set omnifunc=pythoncomplete#Complete 
autocmd FileType JavaScript set omnifunc=javascriptcomplete#CompleteJS 
""/////////////////////////////////////////

"绑定自动补全的快捷键<C-X><C-O>到<leader>; 
""imap <leader>; <C-n><C-p> 

"去除空行
"nnoremap <F2> :g/^\s*$/d<CR>


"设置tab操作的快捷键，绑定:tabnew到<leader>t，绑定:tabn, :tabp到<leader>n, 
"<leader>p 
map <leader>t :tabnew<CR> 
map <leader>n :tabn<CR> 
map <leader>p :tabp<CR> 

"安装TagList插件
let Tlist_Ctags_Cmd='/usr/bin/ctags'
let Tlist_Sort_Type='name'   "按照名次排序
let Tlist_Auto_Open=1
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
"let Tlist_Use_Left_Window=1
let Tlist_Use_Right_Window=1
let Tlist_Enable_Fold_Column=1  "显示折叠树
let Tlist_WinWidth=25           " 设置Taglist的宽度
let Tlist_WinHeight=30			" 设置Taglist的高度
"设定开关Taglist插件的快捷键为F4，可以在VIM的左侧栏列出函数列表等 
map <F4> :Tlist<CR> 

"安装NERDTreeToggle插件
map <F2> :silent! NERDTreeToggle<CR>
"autocmd vimenter * NERDTree
let NERDTreeWinPos="left"
"let NERDTreeWinPos="right"
let NERDTreeShowBookmarks=1

"用cscope支持 
set csprg=/usr/bin/cscope 

"Set winManager
let g:AutoOpenWinManager=1
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

"安装ctags插件
set tags=tags;
set autochdir


"键盘命令
map <S-Left> :tabp<CR>
map <S-Right> :tabn<CR>
map <C-A> ggVG$"+y
imap <C-v> <Esc>"*pa
imap <C-a> <Esc>^
vmap <C-c> "+y

"set miniBUfExplorer
let g:miniBufExplMapWindowNavArrows=1 

"使用<leader>e打开当前文件同目录中的文件 
if has("unix") 
map ,e :e <C-R>=expand("%:p:h") . "/" <CR> 
else 
map ,e :e <C-R>=expand("%:p:h") . "\" <CR> 
endif 

"设置程序的运行和调试的快捷键F5和Ctrl-F5 
map <F5> :call CompileRun()<CR> 
map <C-F5> :call Debug()<CR> 

"定义CompileRun函数，用来调用进行编译和运行 
func! CompileRun() 
exec "w" 
"C程序 
if &filetype == 'c' 
	exec "!g++ % -g -o %<" 
	exec "!time ./%<" 
"C++程序
elseif &filetype == 'cpp'
	exec "!g++ % -g -o %<"
	exec "!time ./%<"
"Java程序 
elseif &filetype == 'java' 
	exec "!javac %" 
	exec "!java %<" 
endif 
endfunc 
"结束定义CompileRun 

"定义Debug函数，用来调试程序 
func Debug() 
exec "w" 
"C程序 
if &filetype == 'c' 
exec "!gcc % -g -o %<" 
exec "!gdb %<" 
"Java程序 
elseif &filetype == 'java' 
exec "!javac %" 
exec "!jdb %<" 
endif 
endfunc 
"结束定义Debug 


"定义函数SetTitle，自动插入文件头 
func SetTitle() 
"如果文件类型为.sh文件 
if &filetype == 'sh' 
call setline(1, "\#########################################################################") 
call append(line("."), "\# File Name: ".expand("%")) 
call append(line(".")+1, "\# Description:  ") 
call append(line(".")+2, "\# Author:  ZhongLin") 
call append(line(".")+3, "\# Created Time: ".strftime("%c")) 
call append(line(".")+4, "\# Note:  ") 
call append(line(".")+5, "\#########################################################################") 
call append(line(".")+6, "\#!/bin/bash") 
call append(line(".")+7, "") 
else 
call setline(1, "/*************************************************************************") 
call append(line("."), " File Name: ".expand("%")) 
call append(line(".")+1, " Description: ") 
call append(line(".")+2, " Author:  ZhongLin") 
call append(line(".")+3, " Created Time: ".strftime("%c")) 
call append(line(".")+4, " Note:  ") 
call append(line(".")+5, " ************************************************************************/") 
call append(line(".")+6, "") 
endif

if expand("%:e") == 'cpp'
	call append(line('.')+7, "#include <iostream>")
	call append(line('.')+8, "")
endif
if expand("%:e") == 'h' || expand("%:e") == 'hpp'   
	call append(line('.')+7, "#ifndef _".toupper(expand("%:r"))."_H_")
	call append(line('.')+8, "#define _".toupper(expand("%:r"))."_H_")
	call append(line('.')+9, "")
	call append(line('.')+10, "#endif")
endif
if &filetype == 'c'
	call append(line('.')+7, "#include <stdio.h>")
	call append(line('.')+8, "#include <stdlib.h>")
	call append(line('.')+9, "#include <string.h>")
	call append(line('.')+10, "")
endif
endfunc
