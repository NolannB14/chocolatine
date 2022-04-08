EXECUTABLES="antman/antman,giantman/giantman,lib/my/libmy.a"

IFS=',' read -ra ADDR <<< $EXECUTABLES
for i in "${ADDR[@]}"; do
    echo "$i"
    if [[ ! -x "./${i}" ]]; then
        exit 1
    fi
done