void aliase(std::string arguments[]) {
        std::ofstream bashrc(home + ".bashrc", std::ios::app);
        if (!bashrc.is_open()) 
	{ std::cout << "Couldnt open ~/.bashrc\n" << std::endl; exit(1); }
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

