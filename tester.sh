echo "------------------ clear everything ------------------------"

rm files1/*.cor
rm files2/*.cor

echo "\n"

RED="\033[1;31m"
GREEN="\033[1;32m"
NC='\033[0m'

for file in files1/*
do
	echo "\n"
	name=$(echo $file | cut -d/ -f2)
	echo "------------------ try $name ------------------------"
	trimmed=$(echo $name | cut -d. -f1)
	echo "their output: "
	./asm $file
	echo "\n"
	echo "our output: "
	./group-asm files2/$name
	echo "\n"
	if [ -f files1/$trimmed.cor ] && [ -f files2/$trimmed.cor ]
	then
		echo "${GREEN}files are both written${NC}"
		# result=$(diff files1/$trimmed.cor files2/$trimmed.cor)
		# if [ $(echo $result | wc > 0) ]
		# then
		# 	echo "${RED}Files not equal...${NC}"
		# else
		# 	echo "${GREEN}Congrats :)${NC}"
		# fi
	elif [ ! -f files1/$trimmed.cor ] && [ ! -f files2/$trimmed.cor ]
	then
		echo "${GREEN}both files are not written${NC}"
	else
		echo "${RED}PROBLEM${NC}"
	fi

done
