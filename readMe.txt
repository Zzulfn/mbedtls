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
     3.1 通过MD4/5 hash128, hash256 等函数把任意长度数据变成固定长度数据。这个固定长度数据就是：散列值，消息摘要，摘要。用于检测信号完整性
     3.2 用途 
           3.2.1 消息完整性检验
           3.2.2 构造伪随机数生成器，它可以由单个秘钥派生出多个秘钥。
           3.2.3 消息认证。消息认证由：单向散列+共享秘钥。 这样就可以检测错误，创改，伪装。 应为秘钥其他人可能不知道。
           3.2.4 数字签名。先将数据经行计算摘要，然后对摘要经行签名。

     3.3 成员：MD4/MD5 hash1 以找到破解方法。hash 256 hash384 hash 512 没有被破解
          3.3.1   通用接口：mbedtls_md_context 结构体
          3.3.2   mbedtls_md_infor_t *info,
          3.3.3   mbedtls_md_init();// 设为0.
          3.3.4   mbedtls_md_setup；
          3.3.5   mbedtls_md_starts; //start 
          3.3.6   mbedtls_md_update // 可以多次使用
          3.3.7   mbedtls_md_finish;
          3.3.8   free
                    
                        
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

