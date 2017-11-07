# twemproxy-reload 以0.4.1为基础改造，具有平滑重启功能

**twemproxy作为redis集群实现方式，被广泛使用，但是原生的twemproxy却不具备平滑重启功能，在主从切换（一般使用sentinel）修改twemproxy配置并重启
twemproxy时，会丢失大量数据。本分支参考nginx平滑重启方式，在原生0.4.1的基础上改造，具有平滑重启功能

## Build

跟安装twemproxy一样

    $ git clone git@github.com:gcliupeng/twemproxy-reload.git
    $ cd twemproxy-reload
    $ autoreconf -fvi
    $ ./configure --enable-debug=full
    $ make
    $ src/nutcracker -h

