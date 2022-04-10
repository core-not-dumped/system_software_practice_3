#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#define TEXT "song yu seok"
#define INPUT_LINE_TEST_NUM 2
using namespace std;
class StringVar{
    public:
        StringVar(int size);
        StringVar();
        StringVar(const char a[]);
        StringVar(const StringVar& string_obj);
        ~StringVar();
        int length() const;
        void input_line(istream& ins);
        friend ostream& operator <<(ostream& outs, const StringVar& the_string);
        void operator =(const StringVar& right_side);
        char *get_value();
    private:
        char *value;
        int max_length;
};

class Text{
    public:
        Text(int size);
        Text();
        Text(const char a[]);
        Text(const Text& text_obj);
        ~Text();
        int length() const;
        void input_line(istream& ins);
        friend ostream& operator <<(ostream& outs, const Text& the_string);
        void operator =(const Text& text);
    private:
        StringVar* word;
        int max_length;
};

Text::Text(int size) : max_length(size){
    word = new StringVar[max_length + 1];
    word[0] = StringVar(" ");
    //construct with size
}
Text::Text() : max_length(50){
    word = new StringVar[max_length + 1];
    word[0] = StringVar(" ");
    //default constructor
}
Text::Text(const char a[]){

    int len_a = strlen(a);
    int word_num = 1;
    for(int i=0;i<len_a;i++)
        if(a[i] == ' ') word_num++;

    max_length = word_num;
    word = new StringVar[word_num + 1];
    
    int pre_word_num = 0;
    int i = 0;
    while(1)
    {
        if(i >= len_a)  break;

        int s_i = i;
        for(;i<len_a;i++)
            if(a[i] == ' ') break;
        
        char *str = new char[i - s_i + 1];
        for(int num=s_i, s = 0 ; num<i ; num++, s++)
            str[s] = a[num];
        str[i - s_i] = '\0';

        StringVar tmp_string(str);
        word[pre_word_num++] = tmp_string;
        i++;

        delete [] str;
    }

    word[word_num] = StringVar(" ");

    //construct with array
}
Text::Text(const Text& text_obj){
    (*this).max_length = text_obj.max_length;

    (*this).word = new StringVar[text_obj.max_length + 1];
    for(int i=0;i<text_obj.max_length + 1;i++)
        (*this).word[i] = text_obj.word[i];
    //copy constructor
}
Text::~Text(){
    delete [] (*this).word;
    //destructor
}

int Text::length() const{
    int num = 0;
    for(int i=0;i<max_length;i++)
    {
        if(strcmp(" ", word->get_value()) == 0)    break;
        num++;
    }

    return num;
    //return total stored word num
}

void Text::input_line(istream& ins){
    char *val = new char[1001];
    ins.getline(val, 1001);
    
    int i = 0;
    int pre_word_num = 0;
    int len_val = strlen(val);
    while(1)
    {
        if(i >= len_val)  break;

        int s_i = i;
        for(;i<len_val;i++)
            if(val[i] == ' ') break;
        
        char *str = new char[i - s_i + 1];
        for(int num=s_i,s=0;num<i;num++,s++)
            str[s] = val[num];
        str[i - s_i] = '\0';

        StringVar tmp_string(str);
        if(pre_word_num >= max_length)  break;
        word[pre_word_num++] = tmp_string;
        i++;

        delete [] str;
    }

    word[pre_word_num] = StringVar(" ");
    //get input from command line like StringVar getline
}
ostream& operator <<(ostream& outs, const Text& text){
    for(int i=0;i<text.max_length;i++)
    {
        if(strcmp(text.word[i].get_value(), " ") == 0) break;
        outs << text.word[i] << " ";
    }
    return outs;
    //operator overloading
}
void Text::operator =(const Text& right_side){
    int right_side_len;
    for(right_side_len = 0;right_side_len<right_side.max_length;right_side_len++)
    {
        if(strcmp(right_side.word[right_side_len].get_value(), " ") == 0) break;
    }

    max_length = right_side.max_length;
    word = new StringVar[max_length + 1];

    for(int i=0;i<right_side_len + 1;i++)
        word[i] = right_side.word[i];
    
    //assignment operator overloading
}

StringVar::StringVar(int size) : max_length(size){
    value = new char[max_length + 1];
    value[0] = '\0';
}
StringVar::StringVar() : max_length(20){
    value = new char[max_length + 1];
    value[0] = '\0';
}
StringVar::StringVar(const char a[]) : max_length(strlen(a)){
    value = new char[max_length+1];
    strcpy(value,a);
}
StringVar::StringVar(const StringVar& string_object) : max_length(string_object.length()){
    value = new char[max_length+1];
    strcpy(value,string_object.value);
}
StringVar::~StringVar(){
    delete [] value;
}
int StringVar::length() const{
    return strlen(value);
}
void StringVar::input_line(istream& ins){
    ins.getline(value, max_length+1);
}
ostream& operator <<(ostream& outs, const StringVar& the_string){
    outs << the_string.value;
    return outs;
}
char* StringVar::get_value(){
    return value;
}
void StringVar::operator =(const StringVar& right_side){
    int new_length = strlen(right_side.value);
    if(new_length>max_length){
        delete[] value;
        max_length = new_length;
        value = new char[max_length+1];
    }
    for(int i=0; i<new_length; i++)
        value[i] = right_side.value[i];
    value[new_length] = '\0';
}
void conversation(int max_name_size);

int main()
{
    conversation(20);
    cout << "End of demonstration.\n";
    return 0;
}

void show_string(StringVar the_string){
    cout << the_string << endl;
}
void conversation(int max_name_size)
{
    using namespace std;
    //test deafult constructor
    Text text_default(max_name_size);
    cout << text_default << text_default.length() <<endl;
    //test array constructor
    Text text(TEXT);
    cout << text <<  text.length()<<endl;
    //test copy constructor
    Text text1(text);
    cout << text1 <<  text.length()<<endl;
    //test assignment operator overloading
    Text text2(2);
    text2 = text;
    cout << text2 << text2.length() <<endl;
    // test input_line
    Text text3(INPUT_LINE_TEST_NUM);
    text3.input_line(cin);
    cout << text3 << text3.length() <<endl;
}
