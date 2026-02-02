LIST=( main ) ; DIR=./backend

#---------------------------------------------------------------------#

if [ ! -d "build" ]; then
    mkdir "build"
fi

#---------------------------------------------------------------------#

echo -e "compilling nodepp-doc backend"
for ITEM in "${LIST[@]}" ; do

    if [ -f "./build/$ITEM" ]; then
        echo "-> compiled   $ITEM"; continue
    fi; echo "-> compilling $ITEM"

    g++ -o $DIR/build/$ITEM $DIR/service/$ITEM.cpp -I$DIR/include -lssl -lcrypto -lz

    if [ ! $? -eq 0 ]; then
        echo "exit error"; exit;
    fi

done

#---------------------------------------------------------------------#

echo -e "running nodepp-doc backend" ; ( cd ./backend; ./build/main )
