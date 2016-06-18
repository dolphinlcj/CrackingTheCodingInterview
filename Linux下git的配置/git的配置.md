<<<<<<< HEAD
=======
![Alt text](./git.png)

>>>>>>> 320c659467016e876af103f7339abaaab5ab8f1f
##Linux下git的配置
###需求和环境
- 硬件：一台装有Ubuntu14.04的PC
- 软件：git-core、openssh-server、openssh-client
<<<<<<< HEAD

###Git的安装
- sudo apt-get install git

###Git上传文件到github的配置

####安装ssh协议

=======
###Git的安装
- sudo apt-get install git
###Git上传文件到github的配置
####安装ssh协议
>>>>>>> 320c659467016e876af103f7339abaaab5ab8f1f
1、安装ssh，git是基于ssh协议的：
- sudo apt-get install openssh-server openssh-client

2、启动ssh服务
- sudo /etc/init.d/ssh restart
<<<<<<< HEAD

####申请github账号

本人在windows上已经申请过，也在windows下上传过代码到github仓库中，故此步骤省略。

=======
####申请github账号
本人在windows上已经申请过，也在windows下上传过代码到github仓库中，故此步骤省略。
>>>>>>> 320c659467016e876af103f7339abaaab5ab8f1f
####配置ssh Public Key（公钥）
1、在本地生成ssh 公钥
- ssh -keygen -C 'email' -t rsa
会在用户目录下/home/用户名/.ssh/下建立秘钥文件，这个.ssh是隐藏文件

2、上传公钥到github

在github账户设置里的profile下，选择SSH KEYS选项，然后Add SSH Key，后将/home/用户名/.ssh/id_rsa.pub 中的内容复制进去，上传。
- sudo gedit /home/lcj/.ssh/id_rsa.pub
我是这么打开这个文件，然后复制的。

3、检查链接是否畅通
- ssh -v git@github.com

####上传文件
1、进入所要上传文件的目录：
- git init

2、创建一个本地的仓库origin：
- git remote add origin git@github.com:yourName/yourRepo.git
**your name**: github用户名
**your Repo.git**: 在github中新添加的仓库

3、文件的上传：
- git add ./ **（全部的文件）**
- git add 文件名

4、执行commit命令：
- git commit -m **"说明这次的提交"**

5、执行pull和push命令：
- git pull origin master
- git push origin master
<<<<<<< HEAD

=======
>>>>>>> 320c659467016e876af103f7339abaaab5ab8f1f
> 本文大体上借鉴了Blog：blog.chinaunix.net/uid-24782829-id-3183604.html，并针对自己配置的实际情况做了些改动。