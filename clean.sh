#!/usr/bin/env bash

function traverse_dir() {
    allfile=$(ls -a "$1")

    for file in $allfile; do
        abs_path="$1/$file"
        # 忽略当前目录、上级目录和git目录
        if [ "$file" == "." ] || [ "$file" == ".." ] || [ "$file" == ".git" ]; then
            continue
        elif [ -d "$abs_path" ]; then
            echo "$abs_path"
            traverse_dir "$abs_path"
        else
            echo "$abs_path"
        fi
    done
}

function delete_file() {
    if [ ! -d "$1" ]; then
        # 删除编译生成的文件
        if objdump -d "$1" >/dev/null 2>&1; then
            echo "清理文件" "$1"
            rm -rf "$1"
        # 删除 .DS_Store
        elif [ "$(basename "$1")" == ".DS_Store" ]; then
            echo "清理文件" "$1"
            rm -rf "$1"
        fi
    fi
}

function delete_dir() {
    if [ -d "$1" ]; then
        if [ "$(basename "$1")" == "build" ]; then
            echo "清理目录" "$1"
            rm -rf "$1"
        fi
    fi
}

clean_path=$(
    cd "$(dirname "$0")" || exit
    pwd
)
echo "清理""$clean_path""目录下的垃圾文件"
allfile=$(traverse_dir "$clean_path")

for file in $allfile; do
    delete_file "$file"
    delete_dir "$file"
done

