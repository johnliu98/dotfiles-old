local opts = { noremap = true, silent = true }

local term_opts = { silent = true }

-- Shorten function name
local keymap = vim.api.nvim_set_keymap

--Remap space as leader key
keymap("", "<Space>", "<Nop>", opts)
vim.g.mapleader = " "
vim.g.maplocalleader = " "

-- Modes
--   normal_mode = "n",
--   insert_mode = "i",
--   visual_mode = "v",
--   visual_block_mode = "x",
--   term_mode = "t",
--   command_mode = "c",

-- Normal --
-- Better window navigation
keymap("n", "<C-h>", "<C-w>h", opts)
keymap("n", "<C-j>", "<C-w>j", opts)
keymap("n", "<C-k>", "<C-w>k", opts)
keymap("n", "<C-l>", "<C-w>l", opts)

-- Remove highlights
keymap("n", "<ESC>", "<ESC>:noh<CR>", opts)
keymap("i", "<ESC>", "<ESC>:noh<CR>", opts)

-- Resize with arrows
keymap("n", "<C-Up>", ":resize -2<CR>", opts)
keymap("n", "<C-Down>", ":resize +2<CR>", opts)
keymap("n", "<C-Left>", ":vertical resize -2<CR>", opts)
keymap("n", "<C-Right>", ":vertical resize +2<CR>", opts)

-- Navigate buffers
keymap("n", "<S-l>", ":bnext<CR>", opts)
keymap("n", "<S-h>", ":bprevious<CR>", opts)

-- Formatting
keymap("n", "<S-f>", ":lua vim.lsp.buf.formatting_sync()<CR>", opts)

-- Markdown
keymap("n", "<C-p>", ":!markdown_previewer %<CR>", opts)

-- Insert --

-- Visual --
-- Stay in indent mode
keymap("v", "<", "<gv", opts)
keymap("v", ">", ">gv", opts)

-- Move text up and down
-- keymap("v", "<A-j>", ":m .+1<CR>==", opts)
-- keymap("v", "<A-k>", ":m .-2<CR>==", opts)
keymap("v", "p", '"_dP', opts)

-- Visual Block --
-- Move text up and down
keymap("x", "J", ":move '>+1<CR>gv-gv", opts)
keymap("x", "K", ":move '<-2<CR>gv-gv", opts)
-- keymap("x", "<A-j>", ":move '>+1<CR>gv-gv", opts)
-- keymap("x", "<A-k>", ":move '<-2<CR>gv-gv", opts)

-- Shortcuts for system paths --
keymap('n', 'gh', ':cd /home/john<CR>', opts)
keymap('n', 'gcf', ':cd /home/john/.config<CR>', opts)
keymap('n', 'gca', ':cd /home/john/.cache<CR>', opts)
keymap('n', 'gbi', ':cd /home/john/.local/bin<CR>', opts)
keymap('n', 'gsh', ':cd /home/john/.local/share<CR>', opts)
keymap('n', 'gdo', ':cd /home/john/Documents<CR>', opts)
keymap('n', 'gdl', ':cd /home/john/Downloads<CR>', opts)
keymap('n', 'gpi', ':cd /home/john/Pictures<CR>', opts)
keymap('n', 'gcco', ':cd /home/john/.config/compton<CR>', opts)
keymap('n', 'gccn', ':cd /home/john/.config/conky<CR>', opts)
keymap('n', 'gcdm', ':cd /home/john/.config/dmenu<CR>', opts)
keymap('n', 'gcdu', ':cd /home/john/.config/dunst<CR>', opts)
keymap('n', 'gcdw', ':cd /home/john/.config/dwm<CR>', opts)
keymap('n', 'gcdb', ':cd /home/john/.config/dwmblocks<CR>', opts)
keymap('n', 'gcnv', ':cd /home/john/.config/nvim<CR>', opts)
keymap('n', 'gcra', ':cd /home/john/.config/ranger<CR>', opts)
keymap('n', 'gcst', ':cd /home/john/.config/st<CR>', opts)
keymap('n', 'gcxo', ':cd /home/john/.config/X11<CR>', opts)
keymap('n', 'gcza', ':cd /home/john/.config/zathura<CR>', opts)
keymap('n', 'gczs', ':cd /home/john/.config/zsh<CR>', opts)
keymap('n', 'gbco', ':cd /home/john/.local/bin/color-scripts<CR>', opts)
keymap('n', 'gbdm', ':cd /home/john/.local/bin/dmenu<CR>', opts)
keymap('n', 'gbst', ':cd /home/john/.local/bin/statusbar<CR>', opts)
keymap('n', 'gsdw', ':cd /home/john/.local/share/dwm<CR>', opts)
keymap('n', 'gdkk', ':cd /home/john/Documents/ktk-kassör<CR>', opts)
keymap('n', 'gdmt', ':cd /home/john/Documents/master-thesis<CR>', opts)
keymap('n', 'gpas', ':cd /home/john/Pictures/ascii<CR>', opts)
keymap('n', 'gpsc', ':cd /home/john/Pictures/screenshots<CR>', opts)
keymap('n', 'gpwa', ':cd /home/john/Pictures/wallpapers<CR>', opts)
keymap('n', 'gpwf', ':cd /home/john/Pictures/wallpapers/favorites/<CR>', opts)
