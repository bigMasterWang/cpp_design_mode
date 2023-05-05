#pragma once
/*
当一个对象的行为取决于它的状态, 并且它必须在运行时刻根据状态改变它的行为时, 可考虑用到状态模式

一个目标类, 持有一个状态类, 根据状态不同的, 不同的核心逻辑卸载状态类的不同派生类中, 状态的转换也卸载派生类中
*/