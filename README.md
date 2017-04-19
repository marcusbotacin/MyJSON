# MyJSON
A C++ JSON library

## What this library is not:

This library is not intended to fully replace other C++ JSON implementations.

## So, why this library ?

The goal of this library was to solve two problems of other solutions I found:

* **Data Reordering**: Input order is kept.
* **Memory Exhaustion**: Tuples are immediatly flushed to disk.

## Using

Just include the *lib* directory on your solution

## Limitations

* No list support
* No nested entry support
* 5-entry-limited tuples
* Escapes only the slash character

## Identation

Output JSON is idented based on the defined value of *#define INITIAL_IDENT 0*. No identation depth configuration is implemented yet.

## Bugs

A lot, please report them.

## Tests

A set of tests to check JsonWriter's working.

### Instantiate

Just create and destroy the JsonWriter object:

```
JsonWriter *json = new JsonWriter(file.c_str());
```

Output:

```
{
}
```

### Single.List.Single.Entry

Just a single entry:

```
json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
```
Output:

```
{
	"Libs":
		[
		{
			"field 1":"1"
				,
				"field 2":"2"
					,
				"field 3":"3"
					,
				"field 4":"4"
					,
				"field 5":"5"
		}
		]
}
```

### Single.List.Single.Entry.NULL

Another single entry, without passing all arguments:

```
json->add_to_entry("field 1","1","field 2","2","field 3","3","","","","");
```

Output:

```
{
	"Libs":
		[
		{
				"field 1":"1"
				,
				"field 2":"2"
					,
				"field 3":"3"
		}
		]
}
```

### Single.List.Multiple.Entry

Adding more entries to the previous examples:

```
	json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
```

Output:

```
{
	"Libs":
		[
		{
			"field 1":"1"
			,
			"field 2":"2"
			,
			"field 3":"3"
			,
			"field 4":"4"
			,
			"field 5":"5"
		}
	,
		{
			"field 1":"10"
			,
			"field 2":"20"
			,
			"field 3":"30"
			,
			"field 4":"40"
			,
			"field 5":"50"
		}
	]
}

```

### Multiple.List.Single.Entry

Adding data on a higher entry:

```
	json->add_entry(entry);
	json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
	json->add_entry(entry2);
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
```
Output:

```
{
	"Libs":
		[
		{
			"field 1":"1"
				,
				"field 2":"2"
					,
				"field 3":"3"
					,
				"field 4":"4"
					,
				"field 5":"5"
		}
		]
	,
	"Bins":
		[
		{
			"field 1":"10"
				,
			"field 2":"20"
				,
			"field 3":"30"
				,
			"field 4":"40"
				,
			"field 5":"50"
		}
		]
}
```

### Multiple.List.Multiple.Entry

The most complete example:

```	
	json->add_entry(entry);
	json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
	json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
	json->add_entry(entry2);
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
```

Output:

```
{
	"Libs":
		[
		{
			"field 1":"1"
				,
				"field 2":"2"
					,
				"field 3":"3"
					,
				"field 4":"4"
					,
				"field 5":"5"
		}
	,
		{
			"field 1":"1"
				,
			"field 2":"2"
				,
			"field 3":"3"
				,
			"field 4":"4"
				,
			"field 5":"5"
		}
	]
		,
		"Bins":
			[
			{
				"field 1":"10"
					,
				"field 2":"20"
					,
				"field 3":"30"
					,
				"field 4":"40"
					,
				"field 5":"50"
			}
	,
		{
			"field 1":"10"
				,
			"field 2":"20"
				,
			"field 3":"30"
				,
			"field 4":"40"
				,
			"field 5":"50"
		}
	,
		{
			"field 1":"10"
				,
			"field 2":"20"
				,
			"field 3":"30"
				,
			"field 4":"40"
				,
			"field 5":"50"
		}
	]
}
```

## Usage Example

Consider the following input:

```
{
	"Movies":
	[
		{
			"title":"A New Hope",
			"year":"1977"
		},
		{
			"title":"The Empire Strikes Back",
			"year":"1980"
		},
		{
			"title":"Return of the Jedi",
			"year":"1983"
		}
	]
}

```

It can be parsed by the following python code:

```
f = open(sys.argv[1],"r").read()
l = json.loads(f)

for entries in l['Movies']:
	print("Title",entries['title'])
	print("Year",entries['year'])
```

The following output is generated:

```
('Title', u'A New Hope')
('Year', u'1977')
('Title', u'The Empire Strikes Back')
('Year', u'1980')
('Title', u'Return of the Jedi')
('Year', u'1983')
```
