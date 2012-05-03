#!/bin/bash


my_install()
{
		echo -n "GPL is great?!: "
        if accept; then
            echo -n "najs";
            cp $1 $2
        else
            echo -n "u dun goof";
        fi
		
}
