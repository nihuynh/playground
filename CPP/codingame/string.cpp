remove_if(str.begin(), str.end(), isspace);
for (unsigned i = 0; i < str.length(); i += 4)
{
	cout << str.substr(i, 4) << endl;
}