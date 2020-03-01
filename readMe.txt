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
                    
                        
4）对称加密算法
       4.1   分组加密： ECB， CBC，RTC   
       4.2   填充方法： PKCS7
       4.3   实现过程同散列函数一样
 
5）消息认证码
       5.1  消息认证码HMCA, CCM ,GCM .
       5.2  消息认证码HMCA，1）计算秘钥，秘钥与内部填充异或 组合， 散列 得到A；  2）秘钥与外部填充异或得到B   3) A||B||C 计算散列值。
       5.3  CCM 一次性数据，相关数据，明文， 分组， CBC-MAC 得到tag, to tag CTR 得到T. 对明文进行CTR。
       5.4  GCM 把CBC-MAC 转换为，GF域。在用GCTR。加密。
       
6）伪随机数生成器
      6.1）真：好，满。 假：滴源，外部结构。实际应用中真作为种子，  再通过为随机数生成序列号。
      6.2）生成初始化向量，秘钥，一次性整数。
      6.3） CTR_DRBG 算法。
       

6）RSA算法
     

7）DH秘钥协商

8）ECDH秘钥协商

9）RSA ,DSA，ECDSA 数字签名

10）数字证书X.509

11) TLS 
      11.1 TLS 又分TL记录协议，握手协议，密码变更协议，警告协议，应用数据协议。其格式为再TCPValue 断： type-- version --length 
      11.2 TLS握手协议 
              完整握手：
               1）client  -> server: 我的版本号,我所支持的密码套件,随机数.可选：曲线，坐标， 签名算法，散列函数， 先加密后mCA还是先MAC，后加密
               2）server -> client: 提供32位随机数。1中选一个密码套件。
               3）server -> client: 发送服务器证书，或中间证书。 根证书客户端自己获取。
               4）server -> client: serverKeyExchange:如果使用ECDHE ze则通过这个告诉他。零时公钥匙。及相关参数。
               5）server -> client: 
              会话恢复：
              

12) COAPS

