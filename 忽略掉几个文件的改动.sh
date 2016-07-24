#忽略这两个文件在本地中的改动，不做提交。但仓库版本里仍然有这两个的空文件。
git update-index --assume-unchanged ACM/main.cpp
git update-index --assume-unchanged wkDir/in.txt
git update-index --assume-unchanged wkDir/out.txt
git update-index --assume-unchanged wkDir/res.txt
