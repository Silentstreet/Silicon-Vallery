<!--
 * @Author: your name
 * @Date: 2021-12-28 20:25:43
 * @LastEditTime: 2021-12-28 20:28:56
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /Code/Silicon-Vallery/Zsh/tmux.md
-->
#### tmux安装及其配置

* tmux的安装 *

https://blog.csdn.net/lxyoucan/article/details/121575850

尽量通过源码编译安装，能够安装最新版本


* 配置文件如图所示

```shell

# 从其他地方拷贝文字到tmux下时，默认是tmux的右键菜单，按住Shift再右键就会调出原有的菜单

# Send prefix
set-option -g prefix C-a
unbind-key C-a
bind-key C-a send-prefix

# 更改分割水平和垂直窗口按键
unbind '"'
bind-key v split-window -v
unbind %
bind-key h split-window -h

# Use Alt-arrow keys to switch panes 
bind -n M-Left select-pane -L 
bind -n M-Right select-pane -R 
bind -n M-Up select-pane -U 
bind -n M-Down select-pane -D

# Shift arrow to switch windows
bind -n S-Left previous-window
bind -n S-Right next-window

# Mouse mode
#set -g mode-mouse on
set -g mouse on
set -g monitor-activity on
set -g xterm-keys on
# 开启鼠标点击选择窗格
#set -g mouse-select-pane on
# 开启鼠标点击选择窗口
#set -g mouse-select-window on
# 开启鼠标调节窗格大小
#set -g mouse-resize-pane on

#set -g mouse-resize-pane on
#set -g mouse-select-pane on
#set -g mouse-select-window on

#tmux source .tmux.conf

set-window-option -g mode-keys vi

set -g history-limit 100000
```

= 通过ctrl + b + : 进入到tmux的命令行，　执行source /home/.tmux.conf命令，配置上去 =

