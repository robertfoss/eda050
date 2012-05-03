accept()
{
	while true 
	do
		echo -n "Answer yes or no (y/n): "
		read answer rest_of_input_is_ignored
		case $answer in
			[yY]) return 0;;
			[nN]) return 1;;
			*) echo Please answer y or n;;
		esac
	done
}
