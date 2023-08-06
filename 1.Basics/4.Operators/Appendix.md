
&emsp;
# Appendix 1: 运算符优先级

<table>
  <tr>
    <th>优先级</th>
    <th>操作符</th>
    <th>描述</th>
    <th>例子</th>
    <th>结合性</th>
  </tr>
  <tr>
    <td rowspan="7">1</td>
    <td>()</td>
    <td>调节优先级的括号操作符</td>
    <td>(a + b) / 4;</td>
    <td rowspan="7">从左到右</td>
  </tr>
  <tr>
    <td>[]</td>
    <td>数组下标访问操作符</td>
    <td>array[4] = 2;</td>
  </tr>
  <tr>
    <td>-></td>
    <td>通过指向对象的指针访问成员的操作符</td>
    <td>ptr->age = 34;</td>
  </tr>
  <tr>
    <td>.</td>
    <td>通过对象本身访问成员的操作符</td>
    <td>obj.age = 34;</td>
  </tr><tr>
    <td>::</td>
    <td>作用域操作符</td>
    <td>Class::age = 2;</td>
  </tr><tr>
    <td>++</td>
    <td>后置自增操作符</td>
    <td>for( i = 0; i < 10; i++ ) ...</td>
  </tr><tr>
    <td>--</td>
    <td>后置自减操作符</td>
    <td>for( i = 10; i > 0; i-- ) ...</td>
  </tr>

  <tr>
    <td rowspan="10">2</td>
    <td>!</td>
    <td>逻辑取反操作符</td>
    <td>if( !done ) ...</td>
    <td rowspan="10">从右到左</td>
  </tr>
  <tr>
    <td>~</td>
    <td>按位取反(按位取补)</td>
    <td>flags = ~flags;</td>
  </tr>
  <tr>
    <td>++</td>
    <td>前置自增操作符</td>
    <td>for( i = 0; i < 10; ++i ) ...</td>
  </tr>
  <tr>
    <td>--</td>
    <td>前置自减操作符</td>
    <td>for( i = 10; i > 0; --i ) ...</td>
  </tr>
  <tr>
    <td>-</td>
    <td>一元取负操作符</td>
    <td>int i = -1;</td>
  </tr>
  <tr>
    <td>+</td>
    <td>一元取正操作符</td>
    <td>int i = +1;</td>
  </tr>
  <tr>
    <td>*</td>
    <td>解引用操作符</td>
    <td>data = *ptr;</td>
  </tr>
  <tr>
    <td>&</td>
    <td>取地址操作符</td>
    <td>address = &obj;</td>
  </tr>
  <tr>
    <td>(type)</td>
    <td>类型转换操作符</td>
    <td>int i = (int) floatNum;</td>
  </tr>
  <tr>
    <td>sizeof</td>
    <td>返回对象占用的字节数操作符</td>
    <td>int size = sizeof(floatNum);</td>
  </tr>
  

  <tr>
    <td rowspan="2">3</td>
    <td>->*</td>
    <td>在指针上通过指向成员的指针访问成员的操作符</td>
    <td>ptr->*var = 24;</td>
    <td rowspan="2">从左到右</td>
  </tr>
  <tr>
    <td>.*</td>
    <td>在对象上通过指向成员的指针访问成员的操作符</td>
    <td>obj.*var = 24;</td>
  </tr>
  

  <tr>
    <td rowspan="3">4</td>
    <td>*</td>
    <td>乘法操作符</td>
    <td>int i = 2 * 4;</td>
    <td rowspan="3">从左到右</td>
  </tr>
  <tr>
    <td>/</td>
    <td>除法操作符</td>
    <td>float f = 10 / 3;</td>
  </tr>
  <tr>
    <td>%</td>
    <td>取余数操作符</td>
    <td>int rem = 4 % 3;</td>
  </tr>
  

  <tr>
    <td rowspan="2">5</td>
    <td>+</td>
    <td>加法操作符</td>
    <td>int i = 2 + 3;</td>
    <td rowspan="2">从左到右</td>
  </tr>
  <tr>
    <td>-</td>
    <td>减法操作符</td>
    <td>int i = 5 - 1;</td>
  </tr>
  

  <tr>
    <td rowspan="2">6</td>
    <td><<</td>
    <td>按位左移操作符</td>
    <td>int flags = 33 << 1;</td>
    <td rowspan="2">从左到右</td>
  </tr>
  <tr>
    <td>>></td>
    <td>按位右移操作符</td>
    <td>int flags = 33 >> 1;</td>
  </tr>
  

  <tr>
    <td rowspan="4">7</td>
    <td><</td>
    <td>小于比较操作符</td>
    <td>if( i < 42 ) ...</td>
    <td rowspan="4">从左到右</td>
  </tr>
  <tr>
    <td><=</td>
    <td>小于或等于比较操作符</td>
    <td>if( i <= 42 ) ...</td>
  </tr>
  <tr>
    <td>></td>
    <td>大于比较操作符</td>
    <td>if( i > 42 ) ...</td>
  </tr>
  <tr>
    <td>>=</td>
    <td>大于或等于比较操作符</td>
    <td>if( i >= 42 ) ...</td>
  </tr>

  <tr>
    <td rowspan="2">8</td>
    <td>==</td>
    <td>等于比较操作符</td>
    <td>if( i == 42 ) ...</td>
    <td rowspan="2">从左到右</td>
  </tr>
  <tr>
    <td>!==</td>
    <td>不等于比较操作符</td>
    <td>if( i != 42 ) ...</td>
  </tr>
  

  <tr>
    <td rowspan="1">9</td>
    <td>&</td>
    <td>按位与操作符</td>
    <td>flags = flags & 42</td>
    <td rowspan="1">从左到右</td>
  </tr>
  

  <tr>
    <td rowspan="1">10</td>
    <td>^</td>
    <td>按位异或操作符</td>
    <td>flags = flags ^ 42;</td>
    <td rowspan="1">从左到右</td>
  </tr>

  <tr>
    <td rowspan="1">11</td>
    <td>|</td>
    <td>按位或操作符</td>
    <td>flags = flags | 42;</td>
    <td rowspan="1">从左到右</td>
  </tr>

  <tr>
    <td rowspan="1">12</td>
    <td>&&</td>
    <td>逻辑与操作符</td>
    <td>if( conditionA && conditionB ) ...</td>
    <td rowspan="1">从左到右</td>
  </tr>

  <tr>
    <td rowspan="1">13</td>
    <td>||</td>
    <td>逻辑或操作符</td>
    <td>if( conditionA || conditionB ) ...</td>
    <td rowspan="1">从左到右</td>
  </tr>

  <tr>
    <td rowspan="1">14</td>
    <td>	? :</td>
    <td>三元条件操作符</td>
    <td>	int i = (a > b) ? a : b;</td>
    <td rowspan="1">从右到左</td>
  </tr>

  <tr>
    <td rowspan="11">15</td>
    <td>=</td>
    <td>赋值操作符</td>
    <td>int a = b;</td>
    <td rowspan="11">从右到左</td>
  </tr>
  <tr>  
    <td>+=</td>
    <td>复合赋值操作符(加法)</td>
    <td>a += 3;</td>
  </tr>
  <tr>  
    <td>-=</td>
    <td>复合赋值操作符(减法)</td>
    <td>b -= 4;</td>
  </tr>
  <tr>  
    <td>*=</td>
    <td>复合赋值操作符(乘法)</td>
    <td>a *= 5;</td>
  </tr>
  <tr>  
    <td>/=</td>
    <td>复合赋值操作符(除法)</td>
    <td>a /= 2;</td>
  </tr>
  <tr>  
    <td>%=</td>
    <td>复合赋值操作符(取余)</td>
    <td>a %= 3;</td>
  </tr>
  <tr>
    <td>&=</td>
    <td>复合赋值操作符(按位与)</td>
    <td>flags &= new_flags;</td>
  </tr>
  <tr>
    <td>^=</td>
    <td>复合赋值操作符(按位异或)</td>
    <td>flags ^= new_flags;</td>
  </tr>
  <tr>
    <td>|=</td>
    <td>复合赋值操作符(按位或)</td>
    <td>flags |= new_flags;</td>
  </tr>
  <tr>
    <td><<=</td>
    <td>复合赋值操作符(按位左移)</td>
    <td>flags <<= 2;</td>
  </tr>
  <tr>
    <td>>>=</td>
    <td>复合赋值操作符(按位右移)</td>
    <td>flags >>= 2;</td>
  </tr>

  <tr>
    <td rowspan="1">16</td>
    <td>,</td>
    <td>逗号操作符</td>
    <td>for( i = 0, j = 0; i < 10; i++, j++ ) ...</td>
    <td rowspan="1">从左到右</td>
  </tr>

</table>






