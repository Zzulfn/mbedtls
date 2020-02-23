1）OpenSSL 安装 初步使用  OK。
     设置环境变量，例如工具安装在C:\OpenSSL-Win64，则将C:\OpenSSL-Win64\bin；复制到Path中。

     1.1 对称加解密测试
          加密：enc -aes-128-cbc -e -in C:\Users\ASUS\Desktop\test.txt -out C:\Users\ASUS\Desktop\Dick6618.enc -K 06a9214036b8a15b512e03d534120006 -iv 3dafba429d9eb430b422da802c9fac41

          解密：enc -aes-128-cbc -d -in C:\Users\ASUS\Desktop\Dick6618.enc -out  C:\Users\ASUS\Desktop\Dick6618.txt -K 06a9214036b8a15b512e03d534120006 -iv 3dafba429d9eb430b422da802c9fac41
     
     1.2 TLS服务器搭建：GCM
          搭建服务器： s_server --state -cert srv_cert.pem -key srv_privkey.pem -CAfile ca_cert.pem -port 443 -clipher ECDHE-ECDSA-AES256-GCM-SHA384 -www ./
          由于要制作相关证书秘钥此处后面实现。

 2）mebedtls介绍： 采用Apache 2.0 许可协议开源软件加密库。其包括密码学算法，X509证书，TLS/DTLS协议。
      2.1  configs文件夹：参考配置目录包括多个参考配置。
            include文件夹：相关头文件。 包含config.h
            libray文件夹：   核心源代码
            proprams文件夹：工具与例子，包括SSL客户端服务器，X.509证书，公钥算法，加解密工具
            tests:  用测试用例
           
3）单向散列函数
     3.1 

3）对称加密算法

4）消息认证码

5）伪随机数生成器

6）RSA算法

7）DH秘钥协商

8）ECDH秘钥协商

9）RSA ,DSA，ECDSA 数字签名

10）数字证书X.509

11) TLS 

12) COAPS

