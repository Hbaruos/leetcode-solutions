class TimeLimitedCache {
    cache = new Map<number, { value: number; timeout?: NodeJS.Timeout | undefined }>();
    
    set(key: number, value: number, duration: number): boolean {
        const existingValue = this.cache.get(key);

        if (existingValue) {
            clearTimeout(existingValue.timeout);
        }

        const timeout = setTimeout(() => this.cache.delete(key), duration);

        this.cache.set(key, { value, timeout });
        return !!existingValue;
    }

    get(key: number): number {
        const entry = this.cache.get(key);
        return entry ? entry.value : -1;
    }

    count(): number {
        return this.cache.size;
    }
}

