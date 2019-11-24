#include <stdio.h>

#include <sys/types.h>

#include <string.h>



struct decoded_icmp 
{
	
	unsigned int type,
	
	code,
	
	checksum,
	
	id,
	
	seqno;

};


void demarshall(unsigned char bytes[], struct decoded_icmp *out)

{
	
	out->type = (u_int16_t)bytes[0]<<0;	
	
	out->code = (u_int16_t)bytes[1]<<0;
	
	out->checksum = ((u_int16_t) bytes[3]<<0) | ((u_int16_t) bytes[2]<<8);

	out->id = ((u_int16_t) bytes[5]<<0) | ((u_int16_t) bytes[4]<<8);	

	out->seqno = ((u_int16_t) bytes[7]<<0) | ((u_int16_t) bytes[6]<<8);

}



int main()

{
	
	struct decoded_icmp out;
	
	unsigned char bytes[] = { 1, 2, 3, 69, 6, 120, 9, 171 };
	
	demarshall(bytes, &out);
	
	printf("%08x, %08x, %08x, %08x, %08x\n", out.type, out.code, out.checksum, out.id, out.seqno);

	return 0;

}
