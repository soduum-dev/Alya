void aliase(std::string arguments[]) {
        std::ofstream bashrc(home + ".bashrc", std::ios::app);
        if (!bashrc.is_open()) 
	{ std::cout << "Cant open ~/.bashrc\n" << std::endl; exit(1); }
        bashrc 
		<< "\n" << arguments[1] << " " 
		<< arguments[2] 
		<< "=" 
		<< "\"" << arguments[3] << "\""<< "\n\n";
        std::cout << "Added alias! Re-open your terminal\nGood Luck\n";
        bashrc.close();
	std::system("source ~/.bashrc");
	exit(0);
}


int how_many_slices(std::string *str) {
	int cnt = 0; // i copy str bcse i dont want to write -> to use method, when i actually have an pointer.
			// ok i write this ->, anyway its forever
	for (unsigned long i = 0; i < str->length(); i++) {
		if (str->at(i) == ',') { cnt++; }
	} // how many ',' in string?
	return cnt;
}

void aliases(std::string they[]) {

	for (unsigned long i = 2; i < 4; i++) {
		if (they[i][0] == ',') { they[i][0] = ' '; }
		if (they[i][they->length() - 1] == ',') { they[i].resize(they->length() - 1); }
	}


	// open ~/.bashrc
	std::ofstream bashrc{home + ".bashrc", std::ios::app};
	if (!bashrc.is_open()) { std::cout << "Cant open ~/.bashrc\n"; exit(1); }
	// counting alias and values from terminal
	int als_cnt = how_many_slices(they + 2) + 1;
	int val_cnt = how_many_slices(they + 3) + 1;
	
	// make they as different strings
	std::string aliases[als_cnt];
	std::string values[val_cnt];
	
	// 
	int last_alias = 0;
	int last_value = 0;
	
	// hi spagetti
	unsigned long i = 0;
	for (char current = they[2].at(i); i < they[2].length(); i++) {
		current = they[2].at(i);
		if (current != ',') {
			aliases[last_alias].push_back(current);
		} else {
			last_alias++; 
		}
	}
	
	i = 0;
	for (char current = they[3].at(i); i < they[3].length(); i++) {
		current = they[3].at(i);
		if (current != ',') {
			values[last_value].push_back(current);
		}
		else {
			last_value++;
		}
	}
	
	// for debug
/*	for (unsigned long i = 0; i < als_cnt; i++) {
		std::cout << aliases[i] + "\n";
	}

	for (unsigned long i = 0; i < val_cnt; i++) {
		std::cout << values[i] + "\n";
	}
*/
	std::string cp; std::cout << "Делать бекап?";
	std::cin >> cp;
	if (cp == "y" || cp == "yes" || cp == "Yes") { 
		std::string name;
		std::cout << "enter name of commit without spaces \"std::sin ahh\": ";
			std::cin >> name; 
			name = name + "\'";
				std::string command = 
			std::string{"cp $HOME/.bashrc $HOME/alya/bashrcs_history && cd $HOME/alya/bashrcs_history && git add .bashrc && git commit -m \'"} + name; 
			std::system(command.c_str());
	}
	for (unsigned long als_i = 0, val_i = 0; als_i < als_cnt && val_i < val_cnt; als_i++, val_i++) {
		bashrc << "alias " + aliases[als_i] << "=\'" + values[val_i] << "\'\n";
	
	}
	

}
