echo "------------------ clear everything ------------------------"

rm files1/*.cor > /dev/null 2>&1
rm files2/*.cor > /dev/null 2>&1

RED="\033[1;31m"
GREEN="\033[1;32m"
NC='\033[0m'

for file in files1/*
do
	name=$(echo $file | cut -d/ -f2)
	echo "------------------ try $name ------------------------"
	trimmed=$(echo $name | cut -d. -f1)
	theirs_result=$(./asm $file > /dev/null)
	our_result=$(./group-asm files2/$name)
	if [ -f files1/$trimmed.cor ] && [ -f files2/$trimmed.cor ]
	then
		echo "${GREEN}files are both written${NC}"
		result=$(diff files1/$trimmed.cor files2/$trimmed.cor | rev | cut -d' ' -f1 | rev)
		if [ $result = "differ" ]
		then
			echo "${RED}But files not equal...${NC}"
		else
			echo "${GREEN}And congrats :)${NC}"
		fi
	elif [ ! -f files1/$trimmed.cor ] && [ ! -f files2/$trimmed.cor ]
	then
		echo "${GREEN}both files are not written${NC}"
	else
		echo "${RED}PROBLEM${NC}"
		echo $our_result
	fi

done
