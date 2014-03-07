class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        const int N = tokens.size();
		stack<int> sStack;
		for(int i = 0;i<N;i++){
			if (tokens[i]== "+"){
				if (sStack.size()<2)throw 1;
				int t1 = sStack.top();
				sStack.pop();
				int t2 = sStack.top();
				sStack.pop();
				sStack.push(t1+t2);
			}else if (tokens[i] == "-"){
				if (sStack.size()<2)throw 1;
				int t1 = sStack.top();
				sStack.pop();
				int t2 = sStack.top();
				sStack.pop();
				sStack.push(t2-t1);
			}else if (tokens[i] == "*"){
				if (sStack.size()<2)throw 1;
				int t1 = sStack.top();
				sStack.pop();
				int t2 = sStack.top();
				sStack.pop();
				sStack.push(t1*t2);
			}else if (tokens[i] == "/"){
				if (sStack.size()<2)throw 1;
				int t1 = sStack.top();
				sStack.pop();
				int t2 = sStack.top();
				sStack.pop();
				if (t1==0)throw 0;
				sStack.push(t2/t1);
			}else {
				int tmp = atoi(tokens[i].c_str());
				sStack.push(tmp);
			}
		}
		if (sStack.size()!=1)throw 2;
		return sStack.top();
    }

	
};
