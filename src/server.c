#include "3moku.h"


main(){
	char hostname[16];

	my_stone='o'; peer_stone='x';
	puts("input server's host name: ");
	gets(hostname);
	if((soc=setup_server(hostname,PORT))== -1) exit(1);

	while(1){
		show_plane(); puts("wait");
		if(get_peer_stone()== -1) break;
		show_plane(); puts("go");
		if(put_my_stone()== -1) break;
	}

	close(soc);
}


