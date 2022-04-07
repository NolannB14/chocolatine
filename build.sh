IFS=',' read -ra ADDR <<< $EXECUTABLES
for i in "${ADDR[@]}"; do
    echo "files : ./$i"
    if [[ ! -f "./${i}" ]]; then
        echo 'check'
        exit 1
    fi
done