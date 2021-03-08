ifconfig -a | grep ether | sed 's/ether//g' | sed 's/	 //g' | grep -v media | sed 's/ //g'
