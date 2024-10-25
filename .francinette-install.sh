#!/usr/bin/env bash

dir="$HOME/.local/share/francinette"

rm -rf "$dir"
mkdir -p "$dir" || exit

pushd "$dir" > /dev/null

git clone --recursive https://github.com/xicodomingues/francinette.git "$dir"

pip3 install wheel virtualenv

if ! python3 -m virtualenv venv ; then
	exit 1
fi

# activate venv
. venv/bin/activate

# install requirements
if ! pip3 install -r requirements.txt ; then
	exit 1
fi

popd > /dev/null

bindir="$HOME/bin"
if [ ! -d "$bindir" ]; then
	bindir="$HOME/.local/bin"
	mkdir -p "$bindir"
	ln -s ".local/bin" "$HOME/bin"
fi

cat > "$bindir/francinette" << EOF
#!/usr/bin/env bash

printf "\x1b[48;2;91;206;250m%18s\x1b[0m\n" ""
printf "\x1b[48;2;245;169;184m%18s\x1b[0m\n" ""
printf "\x1b[48;2;255;255;255;30;1m%9s%-9s\x1b[0m\n" "Trans " "rights"
printf "\x1b[48;2;245;169;184m%18s\x1b[0m\n" ""
printf "\x1b[48;2;91;206;250m%18s\x1b[0m\n\n" ""
exec "\$HOME/.local/share/francinette/tester.sh" "\$@"
EOF

chmod +x "$bindir/francinette"
ln -sf "francinette" "$bindir/paco"

sed "\|alias francinette=$HOME/francinette/tester.sh|d" -i "$HOME/.zshrc"
sed "\|alias paco=$HOME/francinette/tester.sh|d" -i "$HOME/.zshrc"

# print help
"$dir/tester.sh" --help

printf "\033[33m... and don't forget, \033[1;37mpaco\033[0;33m is not a replacement for your own tests! \033[0m\n"
printf "\n\x1b[95;4m%s\x1b[0m\n" "Patched francinette installation script courtesy of rosalinadev"
printf "\n\x1b[31;4m%s\x1b[0m\n" "You might need to restart your shell if you had aliases"
