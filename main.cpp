
#include <iostream>
#include "strategy.h"
#include "decorate.h"
#include "proxy.h"
#include "factory_method.h"
#include "prototype.h"
#include "template_method.h"
#include "facade.h"
#include "builder.h"
#include "observer.h"
#include "abstract_factory.h"
#include "state.h"
#include "adapter.h"
#include "memento.h"
#include "composite.h"
#include "Singleton.h"
#include "bridge.h"
#include "command.h"
#include "chain_of_responsibility.h"
#include "mediator.h"
#include "visitor.h"
using namespace std;


int main() {
    //run();
    //decorate_run();
    //proxy_run();
    //factory_method_run();
    //proto_run();
    //template_method_run();
    //facade_run();
    //build_run();
    //observer_run();
    //AbstracyFactory::abstract_factory_run();
    //state_run();
    //ADAPTER::adapter_run();
    //memo_run();
    //composite_run();
    //singleton_run();
    //BRIDGE::bridge_run();
    //command_run();
    //chain_of_reposibility_run();
    //mediator_run();
    VISITOR::visitor_run();
}
/*
四种原则
单一职责原则, 就是一个类只做一个方向的事情
开放-封闭原则, 对扩展开放, 对修改封闭, 当需要修改时,我们就抽象一下, 来隔离以后同类型的修改
里氏替换原则, 子类要能够替换父类, 程序行为没有变化
依赖倒转原则, 细节依赖抽象, 抽象不能依赖细节, 面向接口编程

迪米特法则
如果两个类不直接通信, 那么这两个类就不应当发生直接的相互作用, 如果一个类需要调用另一个类的某个方法,
可以通过第三个类转发这个调用
*/