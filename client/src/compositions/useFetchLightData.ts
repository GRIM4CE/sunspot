import { ref } from 'vue';
import type { LightDataObject } from "@/types/index"

export function useFetchLightData() {
  const data = ref<LightDataObject[] | null>(null);
  const isLoading = ref(true);
  const error = ref<string | null>(null);

  async function fetchLightData() {
    try {
      data.value = await fetch("http://127.0.0.1:5000/api/", {
        method: "GET"
      }).then(async (res) => {
        if(res.ok) {
          console.log(res)
          return await res.json()
        }
      })
    } catch(err: unknown) {
      if (err instanceof Error) {
        error.value = err.message;
      } else {
        error.value = 'An unknown error occurred';
      }
    } finally {
      isLoading.value = false;
    }
  }

  return { data, isLoading, error, fetchLightData };
}