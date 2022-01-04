#!/bin/sh

slack &
zulip &
google-chrome-stable &
conky --config=$XDG_CONFIG_HOME/conky/conky.conf &
conky --config=$XDG_CONFIG_HOME/conky/clock.conf &
