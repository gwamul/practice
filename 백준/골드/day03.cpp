#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

int calculateDecompressedLength(const std::string &s) {
    std::stack<int> lengthStack;
    std::stack<int> countStack;
    int currentLength = 0;
    int num = 0;

    for (int i = 0; i < s.size(); ++i) {


        if (isdigit(s[i])) {
            currentLength++;
        } else if (s[i] == '(') {
            // Push current length and repeat count onto the stacks
            lengthStack.push(currentLength);
            countStack.push(s[i-1]-'0');
            
            // Reset current length and num
            currentLength = 0;
            num = 0;
        } else if (s[i] == ')') {
            // Pop the stacks and calculate the expanded length
            
            int repeatCount = countStack.top();
            //std::cout<< currentLength<<'\n';
            //std::cout<<"repeatCount"<<repeatCount<<'\n';
            countStack.pop();
            currentLength = lengthStack.top()-1 + (currentLength) * repeatCount;
            
            lengthStack.pop();
        }
    
    }

    return currentLength;
}

int main() {
    std::string compressed_str;
    //std::cout << "Enter the compressed string: ";
    std::cin >> compressed_str;

    int decompressed_length = calculateDecompressedLength(compressed_str);
    std::cout << decompressed_length << std::endl;

    return 0;
}
