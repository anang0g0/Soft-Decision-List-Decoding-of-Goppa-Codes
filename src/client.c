#include "3moku.h"


main(){
	char hostname[16];

	my_stone='x'; peer_stone='o';
	puts("input server's host name: "); gets(hostname);
	if((soc=setup_client(hostname,PORT))== -1) exit(1);

	while(1){
		show_plane(); puts("go");
		if(put_my_stone()== -1) break;
		show_plane(); puts("wait");
		if(get_peer_stone()== -1) break;
	}

		close(soc);
}


