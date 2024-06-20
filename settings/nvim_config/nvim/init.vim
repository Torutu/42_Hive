:set number
:set relativenumber
:set autoindent
:set tabstop=4
:set shiftwidth=4
:set smarttab
:set softtabstop=4
:set mouse=a

call plug#begin('~/.config/nvim/plugged')

Plug 'https://github.com/vim-airline/vim-airline'
Plug 'https://www.github.com/preservim/nerdtree'
Plug 'https://www.github.com/preservim/tagbar'

Plug 'https://github.com/Evalir/dosbox-vim-colorscheme'
Plug 'srcery-colors/srcery-vim'
Plug 'https://github.com/preservim/vim-colors-pencil'
Plug 'KabbAmine/yowish.vim'
Plug 'nickaroot/vim-xcode-dark-theme'

Plug 'neovim/nvim-lspconfig'
Plug 'hrsh7th/nvim-cmp'
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'L3MON4D3/LuaSnip'

Plug 'VonHeikemen/lsp-zero.nvim',{'branch': 'compat-07'}
Plug 'https://github.com/nvim-treesitter/nvim-treesitter'

Plug 'David-Kunz/markid'

call plug#end()

:colorscheme srcery
hi Normal guibg=NONE ctermbg=NONE
hi LineNr guibg=NONE ctermbg=NONE
hi SignColumn guibg=NONE ctermbg=NONE

let g:NERDTreeDirArrowExpandable="+"

nnoremap <C-f> :NERDTreeFocus<CR>
nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>

nmap <F8> :TagbarToggle<CR>

lua <<EOF
	local lsp_zero = require('lsp-zero')

	lsp_zero.on_attach(function(client, bufnr)
		-- see :help lsp-zero-keybindings
		-- to learn the available actions
		lsp_zero.default_keymaps({buffer = bufnr})
		end)

	require('lspconfig').clangd.setup({})

	require'nvim-treesitter.configs'.setup {
  markid = { enable = true }
}
--- in your own config you should replace `example_server`
--- with the name of a language server you have installed
EOF
