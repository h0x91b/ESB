{
	'targets': [
		{
			'target_name': 'proxy',
			'sources': [ 
					'src/command.pb.cc',
					'src/responder.cc',
					'src/requester.cc',
					'src/publisher.cc',
					'src/subscriber.cc',
					'src/proxy.cc',
			],
			'cflags': [
				'-I/usr/local/include/', 
				'-std=c++0x', 
				'-pthread', 
				'-DGOOGLE_PROTOBUF_NO_RTTI'
			],
			'xcode_settings': {
					'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
					'OTHER_CFLAGS': [
							'-I/usr/local/include/', 
							'-pthread', 
							'-mmacosx-version-min=10.7',
							'-std=c++0x',
							'-stdlib=libc++',
					],
					'OTHER_CPLUSPLUSFLAGS': [
							'-I/usr/local/include/', 
							'-pthread', 
							'-mmacosx-version-min=10.7',
							'-std=c++0x',
							'-stdlib=libc++',
					]
			},
			'libraries': [
				'-lzmq', 
				'-lprotobuf', 
				'-lhiredis', 
				'-L/usr/local/lib/'
			]
		}
	]
}