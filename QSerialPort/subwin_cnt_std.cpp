#include "subwin_cnt_std.h"
#include "ui_subwin_cnt_std.h"

cnt_std::cnt_std(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cnt_std)
{
    ui->setupUi(this);
    ui->label_guocheng->setStyleSheet("QLabel{background-color:rgb(222,222,222);}");  //设置样式表
    ui->label_jieguo->setStyleSheet("QLabel{background-color:rgb(222,222,222);}");  //设置样式表
    ui->label_guocheng->setAlignment(Qt::AlignRight);
    ui->label_guocheng->setFont(QFont(0,28));
    ui->label_jieguo->setAlignment(Qt::AlignRight);
    ui->label_jieguo->setFont(QFont(0,28));
}

cnt_std::~cnt_std()
{
    delete ui;
}
bool cnt_std::check_error(const QString str)
{
    QString tmp= inputstr.right(1);
    if((str>="0") && (str<="9"))    //数字
    {       
        if(tmp[0]==')')   //数字前面不能为右括号
            return false;
    }

    else if(str=="." )    //小数点
    {
       if(tmp.length()) //小数点前面只能是数字
       {
           if(MatchingBoth(tmp,"0123456789")== -1)  //没找到数字
                return false;
       }
       else             //小数点前面为空
       {
            return false;
       }

       int pos= LastMatchingBoth(inputstr,"+-*/.()");   //反向查找
        if(pos!= -1 &&inputstr[pos]=='.' )        //一串数字只能有一个小数点
        {
            return false;
        }
    }

    else if(str=="+"||str=="-")       //加减号
    {
       if(tmp.length()&& tmp[0]=='.')     //前面不能为:小数点
       {
          return false;
       }
       tmp= inputstr.right(2);
       if(tmp.length()==2)          //前面不能连续有两次加减乘除
       {
           if(tmp[0]=='+'||tmp[0]=='-'||tmp[0]=='*'||tmp[0]=='/'||tmp[0]=='(')
                if(tmp[1]=='+'||tmp[1]=='-'||tmp[1]=='*'||tmp[1]=='/')
                            return false;
       }
    }

    else if(str=="*"||str=="/")       //乘除号
    {
         if(tmp.length())       //前面不能为:左括号,小数点,加减乘除,
         {
             if(MatchingBoth(tmp,"(.+-*/")!= -1) //查找左括号,小数点,加减乘除
             {
                 return false;
             }
         }
         else                   //乘除号前面不能为空
              return false;
    }

    else if(str=="(")       //左括号
    {
        if(tmp.length())             //前面不能为:右括号,数字,小数点
        {
            if(MatchingBoth(tmp,")0123456789.")!= -1) //查找右括号,数字,小数点
            {
                return false;
            }
        }

        tmp= inputstr.right(2);
        if(tmp.length()==2)          //前面不能连续有两次加减乘除
        {
             if(tmp[0]=='+'||tmp[0]=='-'||tmp[0]=='*'||tmp[0]=='/')
                 if(tmp[1]=='+'||tmp[1]=='-'||tmp[1]=='*'||tmp[1]=='/')
                             return false;
        }
         bracket_cnt++;
    }

    else if(str==")")       //右括号
    {
       if(bracket_cnt==0)  //前面没有左括号
           return false;

        if(tmp.length())             //前面不能为:加减乘除,小数点,左括号
        {
           if(MatchingBoth(tmp,"+-*/.(")!= -1) //查找加减乘除,小数点,左括号
           {
               return false;
           }
        }
        else                    //右括号前面不能为空
           return false;

        bracket_cnt--;
    }

    else if(str=="<-")       //<-
    {
        if(inputstr.length())
            inputstr.chop(1);
        else
            return false;
    }

    else if(str=="C")       //清空
    {
        inputstr.clear();
        bracket_cnt=0;
    }

//    else if(text=="="&& line.length())
//    {
//        QString ret=mDec.Result(line);
//        if(ret==NULL)   //除数为0
//        {
//            line += " : ";
//            line +="除数不能为0";
//        }
//        else if(ret=="Error")
//         {
//            line += ":";
//            line +="格式出错";
//         }
//         else
//         {
//             line += "=";
//             line += ret;
//         }
//        ClearLine =1;
//    }
    return true;
}
int  cnt_std::LastMatchingBoth(QString& str1,const char* str2)      //反向匹配str1和str2
{
    for(int i=str1.length();i>=0;i--)
    {
        for(unsigned int j=0;j<strlen(str2);j++)
            if(str1[i]==str2[j])
                 return i;
    }
   return -1;
}

int  cnt_std::MatchingBoth(QString& str1,const char* str2)          //匹配str1和str2,判断str1是否有str2的字符
{
    for(int i=0;i<str1.length();i++)
    {
        for(unsigned int j=0;j<strlen(str2);j++)
            if(str1[i]==str2[j])
                 return i;
    }
   return -1;
}
QQueue<QString> cnt_std::Split(const QString& exp)          //分离前缀
{
    QQueue<QString> ret;
    QString num="";

    for(int i=0;i<exp.length();i++)
    {
        if( (exp[i]=='.') || ( (exp[i]>='0') && (exp[i]<='9') ))    //判断小数点和数字
        {
            num += exp[i];
        }

        else if(exp[i]== '(' || exp[i]== ')' || exp[i]== '*' || exp[i]== '/'  )
        {
            if(!num.isEmpty())
            {
                ret.enqueue(num);        //将数字入队列
                num.clear();
            }
            ret.enqueue(exp[i]);
        }

        else if(exp[i]== '+' || exp[i]== '-')           // + - 需要特殊处理
        {
            if(i==0)       //表达式开头,说明是正负号
            {
             num+= exp[i];
            }

            else if(exp[i-1]=='(' || exp[i-1]=='+' || exp[i-1]=='-' || exp[i-1]=='*' || exp[i-1]=='/')
            {
             num+= exp[i];
            }
            else        //否则是加减运算符
            {
                if(!num.isEmpty())
                {
                    ret.enqueue(num);        //将数字入队列
                    num.clear();
                }
             ret.enqueue(exp[i]);
            }
        }
    }

    if(!num.isEmpty())         //遍历完成,判断是否还有数字
    {
        ret.enqueue(num);
        num.clear();
    }
return ret;
}

QQueue<QString> cnt_std::Transfer(QQueue<QString>& exp)     //将中缀队列转换为后缀队列
{
    QStack<QString> stack;
    QQueue<QString> ret;
    bool num_ok;
    QString symbol;

    while(!exp.isEmpty())
    {
      symbol = exp.dequeue();   //出队列
      symbol.toDouble(&num_ok);

      if(num_ok==true)          //数字
      {
           stack.push(symbol);
      }

      else if(symbol=="+"||symbol=="-")
      {
          while(!stack.isEmpty() &&(stack.top()!="("))
          {
              ret.enqueue(stack.pop());     //取出栈顶运算符并入队列
          }
          stack.push(symbol);
      }

      else if(symbol=="*"||symbol=="/")
      {
          while(!stack.isEmpty() && (stack.top()!="(") && (stack.top()!="+") && (stack.top()!="-"))
          {
              ret.enqueue(stack.pop());     //取出栈顶运算符并入队列
          }
          stack.push(symbol);
      }

      else if(symbol == "(")
      {
         stack.push(symbol);
      }

      else if(symbol ==")")
      {
          while(!stack.isEmpty() && (stack.top()!="("))
          {
              ret.enqueue(stack.pop());     //取出栈顶运算符并入队列
          }
          if(stack.top()=="(")
            stack.pop();
      }
    }

    while(!stack.isEmpty()&& (stack.top()!="("))         //遍历完成,判断栈里是否为空
    {
       ret.enqueue(stack.pop());     //取出栈顶运算符并入队列
    }return ret;
}

QString cnt_std::ValidNum(QString str)
 {
    QString num;

    if(str.indexOf(".")== -1) //判断是否小数
        return str;

    while(str.length()>1)   //避免0被去掉
    {
         num=str.right(1);
         if(num=="."||num=="0")
         {
             str.chop(1);
             if(num==".")
                 return  str;
         }
         else
             return str;
    }
    return str;
}

QString cnt_std::Calculate(QString& l,QString& op,QString& r )
{
    double left,right,res;
    QString ret="";
    left = l.toDouble();
    right = r.toDouble();
    if(op == "+")
    {
        res = left + right;
    }

    else if(op == "-")
    {
        res = left - right;
    }

    else if(op == "*")
    {
        res = left * right;
    }

    else if(op == "/")
    {
        if( (right>(-0.000000000000001)) && (right<(0.000000000000001)) )   //判断除数为0
            return NULL;
        else
            res = left/right;
    }

    ret.sprintf("%f",res);
    return ret;
}

QString cnt_std::Calculate(QQueue<QString>& exp)            //将后缀队列计算出结果
{
    QStack<QString> stack;
    QString symbol,L,R,op,ret;
    bool num_ok;

    while(!exp.isEmpty())
    {
      symbol = exp.dequeue();   //出队列
      symbol.toDouble(&num_ok);

      if(num_ok==true)      //数字
      {
        stack.push(symbol);
      }
      else                  //运算符
      {
          if(stack.size()<2)
              return "Error";

          R= stack.pop();
          L= stack.pop();
          ret = Calculate(L,symbol,R );
          if(ret==NULL)
              return ret;

          stack.push(ret);
      }
    }
    if(stack.size()==1) //遍历完成,结果只有一个
    {
         return ValidNum(stack.pop());
    }
    else
    {return "Error";
    }
}

QString cnt_std::Result(const QString& exp)
{
      QQueue<QString> q=Split(exp); //分离中缀
      q=Transfer(q);                //转换为后缀
      return Calculate(q);          //返回结果
}
void cnt_std::on_pushButton_0_clicked()
{   
    if(check_error("0") != false)
    {
        inputstr += "0";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_1_clicked()
{
    if(check_error("1") != false)
    {
        inputstr += "2";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_2_clicked()
{
    if(check_error("2") != false)
    {
        inputstr += "2";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_3_clicked()
{
    if(check_error("3") != false)
    {
        inputstr += "3";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_4_clicked()
{
    if(check_error("4") != false)
    {
        inputstr += "4";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_5_clicked()
{
    if(check_error("5") != false)
    {
        inputstr += "5";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_6_clicked()
{
    if(check_error("6") != false)
    {
        inputstr += "6";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_7_clicked()
{
    if(check_error("7") != false)
    {
        inputstr += "7";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_8_clicked()
{
    if(check_error("8") != false)
    {
        inputstr += "8";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_9_clicked()
{
    if(check_error("9") != false)
    {
        inputstr += "9";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_jia_clicked()
{
    if(check_error("+") != false)
    {
        inputstr += "+";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_jian_clicked()
{
    if(check_error("-") != false)
    {
        inputstr += "-";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_cheng_clicked()
{
    if(check_error("*") != false)
    {
        inputstr += "*";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_chu_clicked()
{
    if(check_error("/") != false)
    {
        inputstr += "/";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_dengyu_clicked()
{
    inputstr += "=";
    ui->label_guocheng->setText(inputstr);
    QString ret = Result(inputstr);
    ui->label_jieguo->setText(ret);
    inputstr = ret;
}

void cnt_std::on_pushButton_dian_clicked()
{
    if(check_error(".") != false)
    {
        inputstr += ".";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_zheng_fu_clicked()
{
    if(check_error("-") != false)
    {
        inputstr += "-";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_shanchu_clicked()
{
    if(check_error("<-") != false)
    {
        ui->label_guocheng->setText(inputstr);
    }

}

void cnt_std::on_pushButton_qingchu_clicked()
{
    if(check_error("C") != false)
    {
        ui->label_guocheng->setText(inputstr);
        ui->label_jieguo->setText(inputstr);
    }
}

void cnt_std::on_pushButton_kuohao_zuo_clicked()
{
    if(check_error("(") != false)
    {
        inputstr += "(";
        ui->label_guocheng->setText(inputstr);
    }
}

void cnt_std::on_pushButton_kuohao_you_clicked()
{
    if(check_error(")") != false)
    {
        inputstr += ")  ";
        ui->label_guocheng->setText(inputstr);
    }
}
