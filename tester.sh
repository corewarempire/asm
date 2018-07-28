rm files1/*.cor
rm files2/*.cor

for file in files1/*
do
	echo "try $file"
	./asm $file
done

for file in files2/*
do
	echo "try $file"
	./group-asm $file
done

cd files1

for file in *.cor
do
	echo "diff on $file"
	diff $file ../files2/$file
done
