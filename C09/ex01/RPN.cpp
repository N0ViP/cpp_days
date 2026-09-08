#include "RPN.hpp"

bool	parseInput(std::stack<int>& st, std::stringstream& ss)
{
	std::string			buf;
	int					flag = 0, a, b;

	while (ss >> buf)
	{
		if (buf.size() != 1)
			return false;
		
		if (std::isdigit(buf[0]))
		{
			st.push(buf[0] - '0');
			flag++;
			continue ;
		}
		else if (flag < 2)	//stack must containe at least 2 ints
			return false;

		a = st.top();
		st.pop();
		b = st.top();
		st.pop();
		
		switch (buf[0])
		{
			case '+':
				b += a;
				break;
			case '-':
				b -= a;
				break;
			case '*':
				b *= a;
				break;
			case '/':
				b /= a;
				break;
			default:
				return false;
		}
		st.push(b);
		flag--;
	}

	if (st.size() != 1)
		return false;

	return true;
}

