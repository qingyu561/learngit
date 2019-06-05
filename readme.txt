笔记:

*正向代理与反向代理:
    代理服务器(Proxy Serve):

    使用代理服务器:
        1.提高访问速率  
            缓存数据,访问同一数据
        2.防火墙作用
            服务入口,过滤信息,隐藏ip,免受攻击
        3.突破访问限制
            客户机受限制,代理服务器不受限制
    
    正向代理(forward proxy):
        客户端A 想访问服务端C 通过代理服务器B 进行访问

    反向代理(reverse proxy):
        客户端A 向代理服务器B借钱,B没有钱,B能够从CDEF手中拿到钱给A
    
    正向代理的应用:
    1. 访问原来无法访问的资源 
    2. 用作缓存,加速访问速度 
    3. 对客户端访问授权,上网进行认证 
    4. 代理可以记录用户访问记录（上网行为管理）,对外隐藏用户信息

    反向代理的应用:
    1. 保护内网安全 
    2. 负载均衡 
    3. 缓存,减少服务器的压力 
       Nginx作为最近较火的反向代理服务器,安装在目的主机端,主要用于转发客户机请求,后台有多个http服务器提供服务,nginx的功能就是把请求转发给后台的服务器,决定哪台目标主机来处理当前请求。

    正向代理和反向代理的区别:
    位置不同 
    正向代理,架设在客户机和目标主机之间; 
    反向代理,架设在服务器端;
    代理对象不同 
    正向代理,代理客户端,服务端不知道实际发起请求的客户端; 
    反向代理,代理服务端,客户端不知道实际提供服务的服务端; 

*Nginx
#编译开启SSL模块
./configure --prefix=/opt/nginx -with-openssl=/source/openssl-1.0.2l --with-openssl-opt="" --with-http_ssl_module
#nginx.conf
server  
 listen 443 ssl;
 servername www.example.com; 
 ssl_protocols SSLv3 TLSv1 TLSv1.1 TLSv1.2;
#让服务器选择要使用的算法套件
 ssl_prefer_server_ciphers on;
#分配1MB的共享内存缓存，约4000个会话
 ssl_session_cache shared:ssl_session_cache:1M;
#设置会话缓存过期时间为24小时
 ssl_session_timeout 1440m;
#要求客户端身份验证
 ssl_verify_client on;
#指定客户端证书到根证书的最大证书路径长度
 #ssl_verify_depth 2;
#ssl_ciphers
 ssl_certificate_key server.key; #配置在http section 所有server共享
#证书：服务器证书在最前面，后面是所有必要的中间证书，不需要根证书(是否保留根证书) 证书链顺序，一级CA在前
 ssl_certificate server.crt; 配置在http section 所有server共享
#私钥密码配置文件,每个密码一行，会遍历所有密码
 #ssl_password_file $HOME/etc/https/password
#指定允许签发客户端证书的CA证书，证书名称
#将被发送给用户用于客户端证书选取
 ssl_client_certificate sub-ca.crt;
#完整证书链中需要包含的其他CA证书
 ssl_trusted_certificate root-ca.crt;
#证书吊销列表，文件有更新时Nginx需要重新加载
 #ssl_crl revoked-certificate.crl
#TLS缓存区调优，默认16KB，减少TLS缓冲区大小，可以显著减少首字节时间，但可能会降低连接的吞吐量，特别是当你需要发送大量的数据时
 #ssl_buffer_size 1400
#记录日志
 #log_format ssl "$time_local $server_name $remote_addr $connection 
$connection_requests $ssl_protocol $ssl_cipher $ssl_session_id $ssl_session_reused
#记录TLS连接信息
 #access_log /path/to/ssl.log ssl;
}

Java是一种技术，它由四方面组成：
    Java编程语言、Java类文件格式、Java虚拟机和Java应用程序接口(Java API)。
Java虚拟机的体系结构：
    每个JVM都有两种机制：
        ①类装载子系统：装载具有适合名称的类或接口
        ②执行引擎：负责执行包含在已装载的类或接口中的指令
    每个JVM都包含：
        方法区、Java堆、Java栈、本地方法栈、指令计数器及其他隐含寄存器

        方法区、Java堆、Java栈、本地方法栈、指令计数器及其他隐含寄存器
        