#!/bin/sh

[ "$(xdotool search --name "Slack")" ] || slack &
[ "$(xdotool search --name "Zulip")" ] || zulip &
[ "$(xdotool search --name "Google Chrome")" ] || $BROWSER &
[ "$(xdotool search --class "Conky")" ] ||
    (conky --config=$XDG_CONFIG_HOME/conky/conky.conf &
     conky --config=$XDG_CONFIG_HOME/conky/clock.conf) &
