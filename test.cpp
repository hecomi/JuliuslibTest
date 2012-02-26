#include <iostream>
#include <julius/juliuslib.h>

int main(int argc, char* argv[])
{
	// Jconf: configuration parameters
	// load configurations from command arguments
	Jconf *jconf = j_config_load_args_new(argc, argv);
	if (jconf == NULL) {
		std::cout << "Error @ j_config_load_args_new" << std::endl;
		return -1;
	}

	// Recog: Top level instance for the whole recognition process
	// create recognition instance according to the jconf
	Recog *recog = j_create_instance_from_jconf(jconf);
	if (recog == NULL) {
		std::cout << "Error @ j_create_instance_from_jconf" << std::endl;
		return -1;
	}

	// Regster callback
	callback_add(recog, CALLBACK_EVENT_SPEECH_READY, [](Recog *recog, void*) {
		std::cout << "<<< PLEASE SPEAK! >>>" << std::endl;
	}, NULL);

	callback_add(recog, CALLBACK_EVENT_SPEECH_START, [](Recog *recog, void*) {
		std::cout << "...SPEECH START..." << std::endl;
	}, NULL);

	callback_add(recog, CALLBACK_RESULT, [](Recog *recog, void*) {
		for (const RecogProcess *r = recog->process_list; r; r = r->next) {
			WORD_INFO *winfo = r->lm->winfo;
			for (int n = 0; n < r->result.sentnum; ++n) {
				Sentence *s   = &(r->result.sent[n]);
				WORD_ID *seq = s->word;
				int seqnum   = s->word_num;
				for (int i = 0; i < seqnum; ++i) {
					std::cout << winfo->woutput[seq[i]];
				}
			}
		}
	}, NULL);

	// Initialize audio input
	if (j_adin_init(recog) == FALSE) {
		return -1;
	}

	// output system information to log
	j_recog_info(recog);

	// Open input stream and recognize
	switch (j_open_stream(recog, NULL)) {
		case  0: break; // success
		case -1: std::cout << "Error in input stream" << std::endl; return -1;
		case -2: std::cout << "Failed to begin input stream" << std::endl; return -1;
	}

	// Recognition loop
	int ret = j_recognize_stream(recog);
	if (ret == -1) return -1;

	// exit
	j_close_stream(recog);
	j_recog_free(recog);

	return 0;
}
