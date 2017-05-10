[
    {
        "id": "b1ab4910.46bce",
        "type": "udp in",
        "z": "85eedbc2.9fe0b",
        "name": "",
        "iface": "",
        "port": "8765",
        "ipv": "udp4",
        "multicast": "false",
        "group": "",
        "datatype": "buffer",
        "x": 240,
        "y": 120,
        "wires": [
            [
                "fdd2ad48.de255"
            ]
        ]
    },
    {
        "id": "fdd2ad48.de255",
        "type": "function",
        "z": "85eedbc2.9fe0b",
        "name": "",
        "func": "var payload = [];\nvar now = Date.now();\nvar id = msg.payload.readInt32LE(0);\nfor (i = 0; i < 100; i++)\n{\n  payload.push([{\n    U: msg.payload.readInt32LE(4 * (i + 1)),\n    time: (now + 10 * i) * 1000000\n  }, {\n    ID: id\n  }]);\n}\nmsg.payload = payload;\nreturn msg;\n",
        "outputs": 1,
        "noerr": 0,
        "x": 350,
        "y": 200,
        "wires": [
            [
                "c5604f8.a46763"
            ]
        ]
    },
    {
        "id": "c5604f8.a46763",
        "type": "influxdb out",
        "z": "85eedbc2.9fe0b",
        "influxdb": "8c5b9adf.8327a8",
        "name": "",
        "measurement": "Measurement",
        "x": 460,
        "y": 120,
        "wires": []
    },
    {
        "id": "8c5b9adf.8327a8",
        "type": "influxdb",
        "z": "",
        "hostname": "127.0.0.1",
        "port": "8086",
        "protocol": "http",
        "database": "DB",
        "name": "",
        "usetls": false,
        "tls": ""
    }
]
