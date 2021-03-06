#pragma once

static const stringc version_logs[] = {
	"2012.3.26：建立git",
	"2012.3.26：建立工程和一些头文件，下一步添加线程库、锁等文件",
	"2012.3.27：加线程库、锁，下一步加内存池和allocator",
	"2012.3.28：加alloctor，貌似不用加内存池了，下一步加socket",
	"2012.3.29：加sleep，下一步加socket",
	"2012.3.29：加了抽象客户端和服务器，下一步加具体的接收发送实体",
	"2012.3.30：加了个msg，下一步完善，git突然被墙了，捣鼓了下goagent",
	"2012.3.31：转战bitbucket的hg了吧，fuck gcd",
	"2012.3.31：添加测试工程",
	"2012.3.31：添加thread_recver和thread_sender两个线程收发器",
	"2012.4.1：加上socket、test，编译通过",
	"2012.4.1：加netmsg",
	"2012.4.2：加slot和写包读包",
	"2012.4.3：加flush和fill，下一步具体写socket",
	"2012.4.3：加socket静态函数api，下一步加server端的结构",
	"2012.4.3：加tick，驱动下，加server结构",
	"2012.4.4：加fstring,加了server的listen",
	"2012.4.4：加can_read、can_write等函数",
	"2012.4.4：加accept，fix几个bug",
	"2012.4.5：加getsocketname函数",
	"2012.4.5：加server逻辑，下一步加server发包收包逻辑，ok了就可以联调了",
	"2012.4.7：加server收发包逻辑，下一步加socket缓冲区",
	"2012.4.7：修改server收发包逻辑，下一步加socket缓冲区",
	"2012.4.7：添加socket缓冲区，下一步测试发包收包",
	"2012.4.7：修改netmsg逻辑，下一步加flush和fill",
	"2012.4.7：发包收包调试通过，下一步测试断线和block等",
	"2012.4.7：加了个assert，下一步先移植到linux，在测试端口、断线、block等是否正确",
	"2012.4.8：移植到linux，编成lib，下一步把test移植",
	"2012.4.9：test移植到linux，把cmake挪下位置，下一步测试两个平台互联正确性",
	"2012.4.9：去掉防火墙能连，加上时间函数，精确到ns，下一步添加serve端断线处理",
	"2012.4.9：测试了速度，同机器测试速度还行，发零碎小包速度比较慢，下一步添加serve端断线处理",
	"2012.4.9：断线通知上层的机制需要想想，目前会有空指针问题",
	"2012.4.9：去掉socket线程，太不可控了，还是用经典模式，立即处理消息包，下一步添加配置文件ini",
	"2012.4.9：添加ini配置文件，下一步加日志线程",
	"2012.4.10：添加简单的日志线程，下一步加日志mng，然后就可以开始具体的server了",
	"2012.4.11：添加日志mng，下一步利用引擎写具体的lua机器人，同时加上lua tinker库",
	"2012.4.11：添加app类，下一步加机器人工程",
	"2012.4.12：针对机器人工程的修改",
	"2012.4.12：针对linux的修改",
	"2012.4.12：添加lua库",
	"2012.4.12：添加lua库的lib，针对机器人的修改",
	"2012.4.13：针对机器人的修改",
	"2012.4.14：针对机器人的修改，修改时间函数",
	"2012.4.14：直接添加lua源代码",
	"2012.4.24：修改inifile的bug",
	"2012.4.24：修改inifile的bug，linux下添加调试",
	"2012.4.29：修改下mainapp",
	"2012.5.2：添加event",
	"2012.5.3：修改event",
	"2012.5.4：合并event和msg pro，修改ini为模板",
	"2012.5.4：添加tls",
	"2012.5.6：添加msg函数",
	"2012.5.7：添加file包装",
	"2012.5.7：linux修正",
	"2012.5.8：添加zlib",
	"2012.5.8：下一步准备加lzo压缩玩玩",
	"2012.5.9：加lzo压缩",
	"2012.5.9：linux支持",
	"2012.5.9：修改个bug，下一步打算加加密",
	"2012.5.10：修改个默认参数，后续打算加读表写表库，就是excel那样的txt文件",
	"2012.5.11：加从V8拷来的double函数和debug函数，下一步先加mysql",
	"2012.5.11：加logo，下一步先加mysql",
	"2012.5.12：添加字典树，下一步加敏感词，后续想加性能监控",
	"2012.5.12：修改linux编译",
	"2012.5.12：添加mysql",
	"2012.5.12：mysql的win下改成lib",
	"2012.5.13：加debug版的mysql的lib",
	"2012.5.15：准备加自己的performance，然后是packet包，然后是excel文件",
	"2012.5.16：加线程局部存储定义，下一步加时间sample逻辑",
	"2012.5.17：加perf两个类，下一步继续完善",
	"2012.5.17：加perf函数，下一步验证下输出txt文件",
	"2012.5.18：下一步准备加xml解析，perf就输出xml格式",
	"2012.5.19：添加全局变量定义，下一步测试perf，xml打算自己写一套，tinyxml不怎么好用",
	"2012.5.19：添加expat,下一步先测试perf",
	"2012.5.19：添加数组的分配,测试perf基本没问题，下一步输出perf文件",
	"2012.5.20：添加fileio，顺便改改结构",
	"2012.5.20：添加fserialize，linux下编不过。。。fserialize是专注于序列化，fileio是file的包装",
	"2012.5.22：修正linux下编不过的情况，gcc编过了win编不过，所以还是ifdef下吧",
	"2012.5.24：添加deserialize，下一步输出perf",
	"2012.5.26：租了个调试主机，移植到centos",
	"2012.6.8：把netmsg改成序列化，下一步输出perf",
	"2012.6.8：fix linux编译错误",
	"2012.6.9：为netmsg加读字符串",
	"2012.6.27：下一步加自己的array、hash，优化掉stl，打算去掉perf，还是直接用郑哥的perf，如果需要更高级的，可以用google、intel的工具，或是自己写log记录各种数据",
	"2012.6.28：移除perf，下一步加array",
	"2012.6.30：修改网络底层，移除无用的ser和fileio，下一步加array",
	"2012.7.2：修改效率",
	"2012.7.10：增加了linux64位支持",
	"2012.9.16：修改vs2012编译问题",
	"2012.11.4：添加hashmap",
	"2012.11.11：添加google perf支持",
	"2012.6.6：test",
	"2014.4.13：添加简化版本profile",
	"2014.4.13：下一步加proxy组件",
	"2014.4.14：修复bug，下一步加proxy组件",
	"2014.4.14：添加pprof，proxy组件等genmsg完善了再加，genmsg等现有msg框架稳定，所以先测试下现有框架效率问题，测试效率前提是app能够可控退出，所以先把退出加上，退出考虑到跨平台兼容，用共享内存实现来实现一个命令功能",
	"2014.5.3：移植sharemem api",
	"2014.5.3：添加cmd解析",
	"2014.5.10：分离test测试用例",
	"2014.5.10：添加共享内存实现命令功能，下一步加命令推送工具",
	"2014.5.11：加cmd controller",
	"2014.5.11：重构log",
	"2014.5.11：加clock",
	"2014.5.11：fix linux build",
	"2014.5.14：加client server，下一步加收发包",
	"2014.5.14：加mysql",
	"2014.5.14：linux下合并为一个整体lib",
	"2014.5.15：vc加mysql，下一步加自定义的string",
	"2014.5.17：cmake变结构",
	"2014.5.17：从鬼火里移植string过来，可能有坑，下一步移植array，hashmap等",
	"2014.5.18：移植array，下一步移植pool",
	"2014.5.18：加factory，下一步移植pool",
	"2014.5.18：加pool，下一步加pool基础上的hashmap和hashset",
	"2014.5.19：fix bug",
	"2014.5.22：fix hashset bug，添加insert，下次加find",
	"2014.5.22：加iterator和pool的遍历,下次验证正确性",
	"2014.5.22：加fmath.h,下一步加mathutil",
	"2014.5.23：从softpixel和ue4加mathutil，下一步验证pool",
	"2014.5.25：加完hashset，下次加hashmap",
	"2014.5.26：fix build，下次加hashmap",
	"2014.5.26：加hashmap，下次优化网络层",
	"2014.5.31：加flist,farray, 优化了底层buffer，下一步继续整理网络层",
	"2014.6.1：整理网络层，下一步整理其他模块，然后测试网络层效率，添加消息工具",
	"2014.6.2：测试网络层效率，添加inline",
	"2014.6.2：重构ftrie，下一步加genmsg",
	"2014.6.4：add epoll,下一步加genmsg",
	"2014.6.7：加genmsg，下一步加genxml",
	"2014.6.12：加tinyxml",
	"2014.6.13：加gencfg、genstat",
	"2014.6.14：移植gencfg、genstat",
	"2014.6.21：加sqlite",
	"2014.6.21：加md5",
	"2014.6.21：加crc32、sha1，从rehash_src复制",
	"2014.6.22：加alloc内存池",
	"2014.6.23：fix build",
	"2014.6.24：修复内存池bug，下一步重载所有的malloc",
	"2014.6.25：修复内存池bug，下一步重载所有的malloc",
	"2014.6.25：重载所有的malloc，坑有待验证",
	"2014.6.25：重载window下所有的malloc，debug的delete有问题，需要处理",
	"2014.6.26：重载win下的new、delete有问题",
	"2014.6.26：linux下hook后继续用malloc分配大内存会挂掉，改为用mmap吧，目前没看到问题",
	"2014.6.27：改成hook",
	"2014.6.27：hook calloc函数，下一步搞数据库数据存储",
	"2014.6.28：加了按名字序列化的buffer，下一步加到genmsg里",
	"2014.6.29：加des加密",
	"2014.7.1：更新vs2013",
	"2014.7.1：加到genmsg里",
	"2014.7.2：加test",
	"2014.7.2：fix bug",
	"2014.7.3：从SoftPixelEngine加vector等",
	"2014.7.3：加pcre正则式",
	"2014.7.5：开始加proxy",
	"2014.7.5：加proxy消息",
	"2014.7.8：fix linux build",
	"2014.7.9：加proxy client",
	"2014.7.12：继续修改proxyclient，下一步加proxy的连接处理，底层需要对上层提供通过socketid查找或者直接通过socketid发包",
	"2014.7.12：proxy需要维护id->link,type->links，这样就能满足proxy的定向、广播、hash等需求",
	"2014.7.14：fix linux build",
	"2014.7.22：加wireshark插件",
	"2014.7.23：加wireshark插件，已能加载并显示，下一步整合genmsg里面",
	"2014.7.23：加wireshark插件，tcp特殊处理，下一步整合genmsg里面",
	"2014.7.25：加aes加密，下一步加genmsg的动态解析",
	"2014.7.26：加fproto动态解析",
	"2014.7.26：加fproto校验enum",
	"2014.7.28：fix linux build",
	"2014.7.28：加fproto校验struct,下一步加生成实际的对象体",
	"2014.7.31：加原子操作",
	"2014.8.2：加variable，抽象程序运算，为fproto做准备，同时以后可为脚本语言铺路",
	"2014.8.6：另外专门写了个函数式脚本fuckscript，fuckengine里保留fvariable用作其他用途，fuckscript先放开，下一步实现fproto的struct",
	"2014.9.7：在搞fuckscript，fproto后期打算废弃直接用xml转成的脚本替代，加ptrace方便hook别的进程的系统函数",
	"2014.11.23：fakescript加好了，合入engine，下一步重新审视下整体结构，为正式运用准备",
	"2015.5.28：改名fakengine，下一步重新阅读所有模块，为正式运用准备",
	"2015.5.29：整理修改了所有模块，加release，下一步做下实际的组件",
	"2015.6.3：修改circlebuffer，防止出现过多缺页",
	"2015.6.18：修改calloc，改成对齐",
	"2015.6.29：加快win下编译速度",
	"2015.6.30：修改ARRAY_SIZE宏",
};

static force_inline int32_t fversion()
{
	return c_main_version * 10000 + ARRAY_SIZE(version_logs);
}

static force_inline stringc fversionstr()
{
	stringc ret(c_main_version);
	ret += ".";
	ret += ARRAY_SIZE(version_logs);
	return ret;
}

static force_inline stringc fversionlog(int32_t i)
{
	SAFE_TEST_RET_VAL(i >= 0 && i < (int32_t)ARRAY_SIZE(version_logs), false, "none");
	return version_logs[i];
}

static force_inline stringc flastlog()
{
	return version_logs[ARRAY_SIZE(version_logs) - 1];
}
