type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };

function join(arr1: JSONValue[], arr2: JSONValue[]): JSONValue[] {
	const result: JSONValue = {};

    arr1.forEach(item => {
        result[item['id']] = item;
    });

    arr2.forEach(item => {
        if (result[item['id']]) {
            Object.keys(item).forEach(key => {
                result[item['id']][key] = item[key];
            });
        } else {
            result[item['id']] = item;
        }
    });
    return Object.values(result);
};
