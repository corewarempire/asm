echo "------------------ clear everything ------------------------"

rm files1/*.cor
rm files2/*.cor

echo "\n"

for file in files1/*
do
	name=$(echo $file | cut -d/ -f2)
	echo "------------------ try $name ------------------------"
	trimmed=$(echo $name | cut -d. -f1)
	./asm $file
	./group-asm files2/$name
	diff files1/$trimmed.cor files2/$trimmed.cor
	echo $?
	echo "\n"
done
